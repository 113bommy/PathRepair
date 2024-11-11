#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000 + 20, MAXM = 10 * 1000 + 20, INF = 1e9, MOD = 1e9 + 7;
int a[MAXN][15];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n - 1; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) a[j][s[j] - '0']++;
  }
  cin >> s;
  int cnt = 0, mx = 0;
  s[s.size() + 1] = '0';
  for (int i = 0; i < s.size(); i++)
    if (a[i][s[i] - '0'] == n - 1)
      cnt++;
    else {
      mx = max(mx, cnt);
      break;
    }
  cout << mx << endl;
}
