#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p = 0, k = -1;
  vector<pair<long long, long long> > s;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    p = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'E') p++;
    }
    if (p == n) {
      k = i;
      break;
    }
  }
  if (k != -1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[j][i] == '.') {
          s.push_back(make_pair(j + 1, i + 1));
          break;
        }
      }
    }
    if (s.size() == n) {
      for (int i = 0; i < n; i++)
        cout << s[i].first << " " << s[i].second << endl;
    } else
      cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '.') {
          s.push_back(make_pair(i + 1, j + 1));
          break;
        }
      }
    }
    if (s.size() == n) {
      for (int i = 0; i < n; i++)
        cout << s[i].first << " " << s[i].second << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
