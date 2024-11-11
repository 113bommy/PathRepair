#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 17), CNT = 12, MAX = 1e5 + 10;
int a[MAX];
vector<pair<int, pair<int, int> > > ans;
vector<int> vec;
vector<int> sol[maxn];
int h[maxn];
void Do(vector<int>& vec, int pos) {
  for (int x : vec) {
    int A = __builtin_ctz(x & -x);
    x -= (1 << A);
    int B = __builtin_ctz(x & -x);
    int C = B + B - A;
    ans.push_back({pos - 1 - C, {pos - 1 - B, pos - 1 - A}});
    a[pos - 1 - C] ^= 1;
    a[pos - 1 - B] ^= 1;
    a[pos - 1 - A] ^= 1;
  }
}
void prep(int Size, bool is) {
  vec.clear();
  for (int i = 0; i < maxn; i++) sol[i].clear();
  for (int i = 0; i < Size; i++)
    for (int j = i + 1; j < Size; j++)
      for (int k = j + 1; k < Size + (is ? 5 : 0); k++)
        if (j - i == k - j)
          vec.push_back((1 << i) + (1 << j) + (k >= Size ? 0 : (1 << k)));
  fill(h, h + maxn, 1000);
  queue<int> q;
  q.push(0);
  h[0] = 0;
  while (int((q).size())) {
    int u = q.front();
    q.pop();
    for (int x : vec) {
      if (h[u ^ x] == 1000) {
        h[u ^ x] = h[u] + 1;
        sol[u ^ x] = sol[u];
        sol[u ^ x].push_back(x);
        q.push(u ^ x);
      }
    }
  }
}
int main() {
  prep(CNT, 1);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int pt = n;
  while (pt > 17) {
    int MSK = 0;
    for (int i = 0; i < CNT; i++) MSK = 2 * MSK + a[pt - CNT + i];
    Do(sol[MSK], pt);
    pt -= CNT;
  }
  int last = max(pt, min(n, 10));
  prep(last, 0);
  int MSK = 0;
  for (int i = 0; i < last; i++) MSK = 2 * MSK + a[i];
  Do(sol[MSK], last);
  if (h[MSK] == 1000) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  printf("%d\n", int((ans).size()));
  for (auto P : ans)
    printf("%d %d %d\n", P.first + 1, P.second.first + 1, P.second.second + 1);
  return 0;
}
