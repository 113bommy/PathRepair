#include <bits/stdc++.h>
using namespace std;
const int NMax = 200005;
const int KMax = 13;
int N, M, K;
char S[NMax];
set<pair<int, int> > Set;
int Bit[KMax][KMax][NMax];
int Tree[4 * NMax], Lazy[4 * NMax];
int Perm[KMax];
void buildTree(int K, int L, int R) {
  if (L == R) {
    Tree[K] = S[L] - 'a';
    return;
  }
  buildTree(K * 2, L, (L + R) / 2);
  buildTree(K * 2 + 1, (L + R) / 2 + 1, R);
  Tree[K] = max(Tree[K * 2], Tree[K * 2 + 1]);
}
void propagate(int K, int L, int R) {
  if (Lazy[K] != -1) {
    Tree[K] = Lazy[K];
    if (L != R) {
      Lazy[K * 2] = Lazy[K];
      Lazy[K * 2 + 1] = Lazy[K];
    }
    Lazy[K] = -1;
  }
}
void updateTree(int K, int L, int R, int x, int y, int c) {
  propagate(K, L, R);
  if (L > R || L > y || R < x) return;
  if (L >= x && R <= y) {
    Tree[K] = c;
    if (L != R) {
      Lazy[K * 2] = c;
      Lazy[K * 2 + 1] = c;
    }
    return;
  }
  updateTree(K * 2, L, (L + R) / 2, x, y, c);
  updateTree(K * 2 + 1, (L + R) / 2 + 1, R, x, y, c);
  Tree[K] = max(Tree[K * 2], Tree[K * 2 + 1]);
}
int queryColor(int K, int L, int R, int pos) {
  propagate(K, L, R);
  if (L == R) return Tree[K];
  if (pos > (L + R) / 2) return queryColor(K * 2 + 1, (L + R) / 2 + 1, R, pos);
  return queryColor(K * 2, L, (L + R) / 2, pos);
}
void updateBit(int line, int column, int pos, int val) {
  while (pos <= N) {
    Bit[line][column][pos] += val;
    pos += (pos & (-pos));
  }
}
int sumFrom1(int line, int column, int pos) {
  int ans = 0;
  while (pos >= 1) {
    ans += Bit[line][column][pos];
    pos -= (pos & (-pos));
  }
  return ans;
}
int rangeSum(int line, int column, int left, int right) {
  return sumFrom1(line, column, right) - sumFrom1(line, column, left - 1);
}
void Read() {
  scanf("%d%d%d\n", &N, &M, &K);
  scanf("%s", S + 1);
}
void buildBitAndSet() {
  for (int i = 2; i <= N; i++) {
    if (S[i] == S[i - 1]) continue;
    updateBit(S[i - 1] - 'a', S[i] - 'a', i, 1);
    Set.insert(make_pair(i, (S[i - 1] - 'a') * 10 + (S[i] - 'a')));
  }
}
void Update(int left, int right, int c) {
  updateTree(1, 1, N, left, right, c);
  while (!Set.empty()) {
    auto it = Set.lower_bound(make_pair(left, 0));
    if (it == Set.end() || it->first > right + 1) break;
    int line = it->second / 10, column = it->second - 10 * line;
    updateBit(line, column, it->first, -1);
    Set.erase(it);
  }
  if (right < N) {
    int color = queryColor(1, 1, N, right + 1);
    if (color != c) {
      Set.insert(make_pair(right + 1, c * 10 + color));
      updateBit(c, color, right + 1, 1);
    }
  }
  if (left > 1) {
    int color = queryColor(1, 1, N, left - 1);
    if (color != c) {
      Set.insert(make_pair(left, color * 10 + c));
      updateBit(color, c, left, 1);
    }
  }
}
void answerQuery(int left, int right) {
  if (left == right) {
    printf("1\n");
    return;
  }
  int ans = right - left + 1;
  for (int i = 1; i <= K; i++)
    for (int j = i + 1; j <= K; j++)
      ans -= rangeSum(Perm[i], Perm[j], left + 1, right);
  printf("%d\n", ans);
}
void initializeLazy() {
  for (int i = 1; i <= 4 * N; i++) Lazy[i] = -1;
}
void processQueries() {
  for (int i = 1; i <= M; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r;
      char c;
      scanf("%d%d", &l, &r);
      scanf(" %c", &c);
      Update(l, r, c - 'a');
    } else {
      char c;
      scanf("%c", &c);
      for (int i = 1; i <= K; i++) {
        scanf("%c", &c);
        Perm[i] = c - 'a';
      }
      answerQuery(1, N);
    }
  }
}
int main() {
  Read();
  initializeLazy();
  buildBitAndSet();
  buildTree(1, 1, N);
  processQueries();
  return 0;
}
