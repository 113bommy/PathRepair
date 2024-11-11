#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  string s;
  long long int c = 0, n, m, l, k, i;
  cin >> n >> m;
  cin >> s;
  k = s.length();
  int dis[k];
  for (i = 0; i < k; i++) {
    l = ((int(s[i]) + 1 - int('a')));
    if (l <= 13)
      dis[i] = 26 - l;
    else
      dis[i] = l - 1;
    c += dis[i];
  }
  if (m > c)
    cout << "-1";
  else {
    for (i = 0; i < k; i++) {
      if (dis[i] <= m && int(s[i]) - 97 < 13) {
        cout << char(int(s[i]) + dis[i]);
      } else if (dis[i] <= m && int(s[i]) - 97 >= 13) {
        cout << char(int(s[i]) - dis[i]);
      } else if (dis[i] > m && int(s[i]) - 97 < 13) {
        cout << char(int(s[i]) + m);
      } else if (dis[i] > m && int(s[i]) - 97 >= 13) {
        cout << char(int(s[i]) - m);
      }
      m = m - dis[i];
      if (m <= 0) {
        for (int j = i + 1; j < k; j++) {
          cout << s[j];
        }
        return 0;
      }
    }
  }
  return 0;
}
