#include <bits/stdc++.h>
const int MAXN = (int)1e5 + 17;
using namespace std;
int read_int();
int v[MAXN];
int c[MAXN];
long long dp[MAXN];
int last[MAXN];
pair<long long, int> maxes[3];
int sz = 0;
bool cmp(pair<long long, int> a, pair<long long, int> b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  n = read_int();
  q = read_int();
  for (int i = 0; i < n; i++) v[i] = read_int();
  for (int i = 0; i < n; i++) c[i] = read_int();
  for (int i = 0; i < q; i++) {
    int a, b;
    a = read_int();
    b = read_int();
    sz = 0;
    maxes[sz++] = {0ll, -MAXN};
    for (int j = 0; j < n; j++) dp[c[j]] = -1000000000000000000ll;
    for (int j = 0; j < n; j++) {
      dp[c[j]] = max(dp[c[j]], dp[c[j]] + a * 1ll * v[j]);
      int fl = -1;
      long long MAX = -1000000000000000000ll;
      for (int k = 0; k < sz; k++)
        if (maxes[k].second != c[j])
          MAX = max(MAX, maxes[k].first);
        else
          fl = k;
      dp[c[j]] = max(dp[c[j]], MAX + v[j] * 1ll * b);
      if (fl != -1) {
        maxes[fl].first = dp[c[j]];
        continue;
      }
      if (sz < 2)
        maxes[sz++] = {dp[c[j]], c[j]};
      else {
        if (maxes[1].first > maxes[0].first) swap(maxes[0], maxes[1]);
        if (maxes[1].first < dp[c[j]]) maxes[1] = {dp[c[j]], c[j]};
        if (maxes[1].first > maxes[0].first) swap(maxes[0], maxes[1]);
      }
    }
    long long ans = 0ll;
    sort(maxes, maxes + sz, cmp);
    cout << maxes[0].first << '\n';
  }
}
const int maxl = 100000;
char buff[maxl];
int ret_int, pos_buff = 0;
void next_char() {
  if (++pos_buff == maxl) fread(buff, 1, maxl, stdin), pos_buff = 0;
}
int read_int() {
  ret_int = 0;
  int mns = 1;
  for (; buff[pos_buff] < '0' || buff[pos_buff] > '9'; next_char())
    if (buff[pos_buff] == '-') mns = -1;
  for (; buff[pos_buff] >= '0' && buff[pos_buff] <= '9'; next_char())
    ret_int = ret_int * 10 + buff[pos_buff] - '0';
  return ret_int * mns;
}
