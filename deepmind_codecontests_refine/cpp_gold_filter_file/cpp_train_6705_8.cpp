#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 1e5 + 10;
const int MAXLG = 18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
int n, m, q;
int sq;
long long a[MAXN];
vector<int> second[MAXN];
vector<int> lg;
bool mark[320][MAXN];
int com[MAXN][320];
long long sum[MAXN];
long long inc[MAXN];
void return_ans(int k) {
  long long ans = 0;
  if (second[k].size() < sq) {
    for (int i = 0; i < second[k].size(); i++) {
      ans += a[second[k][i]];
    }
    for (int i = 0; i < lg.size(); i++) {
      ans += com[k][i] * inc[lg[i]];
    }
    cout << ans << "\n";
    return;
  }
  ans += sum[k];
  ans += inc[k] * second[k].size();
  for (int i = 0; i < lg.size(); i++) {
    if (lg[i] == k) continue;
    ans += com[k][i] * inc[lg[i]];
  }
  cout << ans << "\n";
}
void add_to_sum(int k, int x) {
  inc[k] += x;
  if (second[k].size() < sq) {
    for (int i = 0; i < second[k].size(); i++) {
      a[second[k][i]] += x;
    }
    for (int i = 0; i < lg.size(); i++) {
      sum[lg[i]] += com[k][i] * x;
    }
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> q;
  sq = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int t, tmp;
    cin >> t;
    if (t >= sq) {
      lg.push_back(i);
    }
    while (t--) {
      cin >> tmp;
      second[i].push_back(tmp);
      sum[i] += a[tmp];
    }
  }
  for (int i = 0; i < lg.size(); i++) {
    int ind = lg[i];
    for (int j = 0; j < second[ind].size(); j++) {
      mark[i][second[ind][j]] = true;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < lg.size(); j++) {
      for (int k = 0; k < second[i].size(); k++) {
        if (mark[j][second[i][k]]) {
          com[i][j]++;
        }
      }
    }
  }
  while (q--) {
    char c;
    cin >> c;
    if (c == '?') {
      int k;
      cin >> k;
      return_ans(k);
    } else {
      int k, x;
      cin >> k >> x;
      add_to_sum(k, x);
    }
  }
}
