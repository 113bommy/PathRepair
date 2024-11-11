#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
long long row[3][maxn];
int Next[3][maxn];
int dp[maxn];
int n;
struct node {
  int one, two, dp;
  node(int one, int two, int dp) : one(one), two(two), dp(dp) {}
};
vector<node> reg[maxn];
void maxi(int &x, int y) { x = max(x, y); }
void mini(int &x, int y) { x = min(x, y); }
void update(const node &t) {
  maxi(dp[max(t.one, t.two)], t.dp);
  reg[min(t.one, t.two)].push_back(t);
}
void take(int one, int two, int d) {
  if (one < n) {
    update(node(one + 1, two, d));
    int pos = Next[0][one];
    if (pos != -1) update(node(pos + 1, two, d + 1));
  }
  if (two < n) {
    update(node(one, two + 1, d));
    int pos = Next[1][two];
    if (pos != -1) update(node(one, pos + 1, d + 1));
  }
  if (one == two && one < n) {
    int pos = Next[2][one];
    if (pos != -1) update(node(pos + 1, pos + 1, d + 1));
  }
}
int main() {
  scanf("%d", &n);
  for (int d = 0; d < 2; d++)
    for (int i = 0; i < n; i++) {
      scanf("%lld", &row[d][i]);
      if (i) row[d][i] += row[d][i - 1];
    }
  for (int i = 0; i < n; i++) row[2][i] = row[0][i] + row[1][i];
  memset(Next, -1, sizeof(Next));
  for (int d = 0; d < 3; d++) {
    unordered_map<long long, int> m;
    for (int i = n - 1; i >= 0; i--) {
      m[row[d][i]] = i;
      int found = 0;
      if (i) found = row[d][i - 1];
      if (m.count(found)) Next[d][i] = m[found];
    }
  }
  for (int i = 0; i < n; i++) {
    int c = dp[i];
    take(i, i, c);
    int one = INT_MAX;
    int two = INT_MAX;
    for (auto &t : reg[i]) {
      if (t.one == i && t.dp == c + 1) mini(two, t.two);
      if (t.two == i && t.dp == c + 1) mini(one, t.one);
    }
    if (one != INT_MAX) take(one, i, c + 1);
    if (two != INT_MAX) take(i, two, c + 1);
  }
  printf("%d\n", dp[n]);
}
