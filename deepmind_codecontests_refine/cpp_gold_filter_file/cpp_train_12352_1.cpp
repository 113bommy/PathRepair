#include <bits/stdc++.h>
using namespace std;
const int NMax = 100005;
int N, Q;
int A[NMax];
long long Diff[NMax];
long long Min[NMax * 4], Max[NMax * 4], Sum[NMax * 4];
set<int> Plus, Minus;
inline long long mod(long long x) { return max(x, -x); }
void buildTree(int K, int L, int R) {
  if (L == R) {
    Min[K] = Max[K] = Diff[L];
    Sum[K] = mod(Diff[L]);
    return;
  }
  buildTree(K * 2, L, (L + R) / 2);
  buildTree(K * 2 + 1, (L + R) / 2 + 1, R);
  Min[K] = min(Min[K * 2], Min[K * 2 + 1]);
  Max[K] = max(Max[K * 2], Max[K * 2 + 1]);
  Sum[K] = Sum[K * 2] + Sum[K * 2 + 1];
}
void precalcDiff() {
  for (int i = 1; i < N; i++) {
    Diff[i] = A[i] - A[i + 1];
    if (Diff[i] >= 0)
      Plus.insert(i);
    else
      Minus.insert(i);
  }
}
void updTree(int K, int L, int R, int pos, long long val, long long newVal) {
  if (L == R) {
    Min[K] += val;
    Max[K] += val;
    Sum[K] = newVal;
    return;
  }
  if (pos > (L + R) / 2)
    updTree(K * 2 + 1, (L + R) / 2 + 1, R, pos, val, newVal);
  else
    updTree(K * 2, L, (L + R) / 2, pos, val, newVal);
  Min[K] = min(Min[K * 2], Min[K * 2 + 1]);
  Max[K] = max(Max[K * 2], Max[K * 2 + 1]);
  Sum[K] = Sum[K * 2] + Sum[K * 2 + 1];
}
long long queryMax(int K, int L, int R, int x, int y) {
  if (L > R || L > y || R < x) return -100000000000000000;
  if (L >= x && R <= y) return Max[K];
  long long a = queryMax(K * 2, L, (L + R) / 2, x, y);
  long long b = queryMax(K * 2 + 1, (L + R) / 2 + 1, R, x, y);
  return max(a, b);
}
long long queryMin(int K, int L, int R, int x, int y) {
  if (L > R || L > y || R < x) return 100000000000000000;
  if (L >= x && R <= y) return Min[K];
  long long a = queryMin(K * 2, L, (L + R) / 2, x, y);
  long long b = queryMin(K * 2 + 1, (L + R) / 2 + 1, R, x, y);
  return min(a, b);
}
long long querySum(int K, int L, int R, int x, int y) {
  if (L > R || L > y || R < x) return 0;
  if (L >= x && R <= y) return Sum[K];
  long long a = querySum(K * 2, L, (L + R) / 2, x, y);
  long long b = querySum(K * 2 + 1, (L + R) / 2 + 1, R, x, y);
  return a + b;
}
void Update(int x, int y, int val) {
  if (x >= 2) {
    if (Diff[x - 1] >= 0 && Diff[x - 1] - val < 0) {
      Plus.erase(x - 1);
      Minus.insert(x - 1);
    }
    Diff[x - 1] -= val;
    updTree(1, 1, N - 1, x - 1, -val, mod(Diff[x - 1]));
  }
  if (y <= N - 1) {
    if (Diff[y] < 0 && Diff[y] + val >= 0) {
      Minus.erase(y);
      Plus.insert(y);
    }
    Diff[y] += val;
    updTree(1, 1, N - 1, y, val, mod(Diff[y]));
  }
}
void getAns(int x, int y, long long val) {
  long long sum = querySum(1, 1, N - 1, 1, N - 1);
  --x;
  int maxPosPlus = x - 1, minPosMinus = y + 1;
  if (!Plus.empty()) {
    auto it = Plus.upper_bound(y);
    if (it != Plus.begin()) maxPosPlus = *prev(it);
  }
  if (!Minus.empty()) {
    auto it = Minus.upper_bound(x - 1);
    if (it != Minus.end()) minPosMinus = *it;
  }
  if (minPosMinus < maxPosPlus) {
    printf("%I64d\n", val * 2 + sum);
    return;
  }
  long long ans = 0;
  if (maxPosPlus > x) {
    long long m = queryMin(1, 1, N - 1, x, maxPosPlus - 1);
    ans = max(ans, sum + max(-val, val - m * 2) + val);
  }
  if (minPosMinus < y) {
    long long m = queryMax(1, 1, N - 1, minPosMinus + 1, y);
    ans = max(ans, sum + max(-val, val + m * 2) + val);
  }
  if (maxPosPlus >= x && minPosMinus <= y) {
    ans = max(ans, sum - mod(Diff[maxPosPlus]) - mod(Diff[maxPosPlus + 1]) +
                       mod(Diff[maxPosPlus] - val) +
                       mod(Diff[maxPosPlus + 1] + val));
  }
  printf("%I64d\n", ans);
}
void Read() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &Q);
}
void Solve() {
  for (int i = 1; i <= Q; i++) {
    int type, x, y, v;
    scanf("%d%d%d%d", &type, &x, &y, &v);
    if (type == 1)
      getAns(x, y, v);
    else
      Update(x, y, v);
  }
}
int main() {
  Read();
  precalcDiff();
  buildTree(1, 1, N - 1);
  Solve();
  return 0;
}
