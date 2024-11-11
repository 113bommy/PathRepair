#include <bits/stdc++.h>
const int INF = 10e6;
using namespace std;
int dp[10001];
inline void boost() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  boost();
  int n, m;
  pair<string, string> p[10001];
  pair<string, string> p1[10001];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].second = p[i].second + ";";
  }
  for (int i = 1; i <= m; i++) {
    cin >> p1[i].first >> p1[i].second;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (p[i].second == p1[j].second) {
        cout << p1[j].first << " " << p1[j].second << " #" << p[i].first
             << endl;
      }
    }
  }
  return 0;
}
