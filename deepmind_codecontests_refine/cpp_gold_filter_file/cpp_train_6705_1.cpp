#include <bits/stdc++.h>
using namespace std;
const int sn = 330;
long long int ans = 0;
int n, m, q, x, y;
vector<long long> s[100111];
long long int h[100111], a[100111], cnt[100111];
int temp[100111];
bool ish[sn][100111];
int intersect[sn][100111];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(ish, 0, sizeof ish);
  memset(h, 0, sizeof h);
  memset(cnt, 0, sizeof cnt);
  memset(intersect, 0, sizeof intersect);
  long long th = 0, tmp;
  for (int i = 1; i <= m; i++) {
    cin >> x;
    if (x > sn) {
      th++;
      for (int j = 0; j < x; j++) {
        cin >> tmp;
        ish[th][tmp] = 1;
        s[i].push_back(tmp);
        cnt[i] += a[tmp];
        temp[th] = i;
      }
    } else {
      for (int j = 0; j < x; j++) {
        cin >> tmp;
        s[i].push_back(tmp);
      }
    }
  }
  for (int i = 1; i <= th; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < s[j].size(); k++) {
        if (ish[i][s[j][k]]) intersect[i][j]++;
      }
    }
  }
  char c;
  while (q--) {
    cin >> c;
    if (c == '+') {
      cin >> x >> y;
      if (s[x].size() > sn) {
        h[x] += y;
      } else {
        for (int i = 0; i < s[x].size(); i++) {
          a[s[x][i]] += y;
        }
        for (int i = 1; i <= th; i++) {
          cnt[temp[i]] += (intersect[i][x] * y);
        }
      }
    } else {
      cin >> x;
      ans = 0;
      if (s[x].size() > sn) {
        ans = cnt[x];
        for (int i = 1; i <= th; i++) {
          ans += (h[temp[i]] * intersect[i][x]);
        }
      } else {
        for (int i = 0; i < s[x].size(); i++) {
          ans += a[s[x][i]];
        }
        for (int i = 1; i <= th; i++) {
          ans += (h[temp[i]] * intersect[i][x]);
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
