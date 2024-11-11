#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  pair<long long, char> a[n];
  pair<long long, char> b[m];
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    long long ind = s.find('-');
    a[i].first = stoi(s.substr(0, ind));
    a[i].second = s[s.size() - 1];
  }
  for (long long i = 0; i < m; i++) {
    cin >> s;
    long long ind = s.find('-');
    b[i].first = stoi(s.substr(0, ind));
    b[i].second = s[s.size() - 1];
  }
  vector<pair<long long, char>> c, d;
  c.push_back(a[0]);
  d.push_back(b[0]);
  for (long long i = 1; i < n; i++) {
    if (a[i].second == a[i - 1].second) {
      long long x = c.size() - 1;
      c[x].first += a[i].first;
    } else {
      c.push_back(a[i]);
    }
  }
  for (long long i = 1; i < m; i++) {
    if (b[i].second == b[i - 1].second) {
      long long x = d.size() - 1;
      d[x].first += b[i].first;
    } else {
      d.push_back(b[i]);
    }
  }
  n = c.size();
  m = d.size();
  if (m == 1) {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (c[i].second == d[0].second && c[i].first >= d[0].first) {
        ans += (c[i].first - d[0].first + 1);
      }
    }
    cout << ans << endl;
  } else if (m == 2) {
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++) {
      if (c[i].second == d[0].first) {
        if (c[i].first >= d[0].first && c[i + 1].second == d[1].second &&
            c[i + 1].first >= d[1].first) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  } else {
    long long ans = 0;
    long long lps[m - 2];
    lps[0] = 0;
    long long i = 1, len = 0;
    while (i < m - 2) {
      if (d[i + 1].second == d[len + 1].second &&
          d[i + 1].first == d[len + 1].first) {
        len++;
        lps[i] = len;
        i++;
      } else if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
    long long j = 0;
    i = 0;
    while (i < n) {
      if (c[i].second == d[j + 1].second && c[i].first == d[j + 1].first) {
        i++;
        j++;
      } else if (j == 0) {
        i++;
      } else {
        j = lps[j - 1];
      }
      if (j == m - 2) {
        if (i + 1 >= m) {
          if (c[i + 1 - m].second == d[0].second &&
              c[i + 1 - m].first >= d[0].first &&
              c[i].second == d[m - 1].second && c[i].first >= d[m - 1].first) {
            ans++;
          }
        }
        j = lps[j - 1];
      }
    }
    cout << ans << endl;
  }
}
