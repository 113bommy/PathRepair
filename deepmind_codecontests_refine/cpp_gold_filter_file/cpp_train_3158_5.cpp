#include <bits/stdc++.h>
using namespace std;
int t, n, d, i, j, k, m, z;
int main() {
  cin >> n >> d;
  pair<string, string> s[n];
  pair<string, string> p[n];
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second >> a[i];
  }
  if (n == 1) {
    cout << "0";
    return 0;
  }
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (s[i].first == s[j].second && s[i].second == s[j].first &&
          a[j] - a[i] <= d && a[j] - a[i] > 0) {
        p[t].first = s[i].first;
        p[t].second = s[i].second;
        t++;
        s[i].first = "1";
        s[i].second = "5";
        s[j].first = "2";
        s[j].second = "4";
      }
    }
  }
  m = t;
  for (i = 0; i < t; i++) {
    for (j = i + 1; j < t; j++) {
      if (p[i].first == p[j].second && p[i].second == p[j].first) {
        p[j].first = "3";
        p[j].second = "3";
        m--;
      }
      if (p[i].first == p[j].first && p[i].second == p[j].second) {
        p[j].first = "3";
        p[j].second = "3";
        m--;
      }
    }
  }
  for (i = 0; i < t; i++) {
    if (p[i].first != "3") z++;
  }
  cout << z << endl;
  for (i = 0; i < t; i++) {
    if (p[i].first != "3") cout << p[i].first << " " << p[i].second << endl;
  }
}
