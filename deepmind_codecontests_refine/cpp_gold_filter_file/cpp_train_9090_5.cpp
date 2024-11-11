#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[105];
char a[30];
int main() {
  ios_base::sync_with_stdio(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char x;
    string tmp;
    int h = 0, m = 0;
    cin >> x >> h >> x >> m >> x;
    getline(cin, tmp);
    if (x == 'p')
      p[i] = {((h + 12) % 24) == 0 ? 12 : ((h + 12) % 24), m};
    else
      p[i] = {h == 12 ? 0 : h, m};
  }
  int ans = 0, cnt = 1;
  for (int i = 1; i < n; i++) {
    if (p[i].first == p[i - 1].first and p[i].second == p[i - 1].second) {
      cnt++;
      if (cnt > 10) {
        ans++;
        cnt = 1;
      }
    } else {
      cnt = 1;
      if (p[i].first < p[i - 1].first) {
        ans++;
      } else if (p[i].first == p[i - 1].first and
                 p[i].second < p[i - 1].second) {
        ans++;
      }
    }
  }
  cout << ans + 1;
}
