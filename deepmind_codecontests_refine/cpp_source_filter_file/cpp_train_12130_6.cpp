#include <bits/stdc++.h>
using namespace std;
int dir8[8][2] = {{1, 2},  {2, 1},   {-1, 2},  {2, -1},
                  {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
int dir4[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const int INF = 0x3f3f3f3fLL;
const long long LLF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXn = 2e6 + 15;
const int mod = 10007;
struct node {
  int i, r, a;
} s[MAXn];
long long dp[MAXn];
bool cmp(node a, node b) { return a.i < b.i; }
int main() {
  int n, i, ma = 0, j = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i].i >> s[i].r;
    s[i].a = s[i].i - s[i].r - 1;
  }
  sort(s, s + n, cmp);
  for (i = 0; i < 1000010; i++) {
    if (i == s[j].i) {
      if (s[j].a > 0)
        dp[i] = dp[s[j].a] + 1;
      else
        dp[i] = 1;
      j++;
    } else
      dp[i] = dp[i - 1];
    if (ma < dp[i]) ma = dp[i];
  }
  cout << n - ma << endl;
  return 0;
}
