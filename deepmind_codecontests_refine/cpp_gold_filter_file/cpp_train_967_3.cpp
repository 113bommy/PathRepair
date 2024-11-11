#include <bits/stdc++.h>
using namespace std;
long long int biexp(long long int m, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2) res = res * m;
    m = m * m;
    n = n / 2;
  }
  return res;
}
int main() {
  int t = 1;
  while (t--) {
    string s;
    cin >> s;
    string a, b;
    long long int i = 0, mi = 0;
    while (s[i] != ':') {
      if (s[i] == '0' and a.size() != 0)
        a.push_back(s[i]);
      else if (s[i] != '0')
        a.push_back(s[i]);
      i++;
    }
    i++;
    while (i < s.length()) {
      if (s[i] == '0' and b.size() != 0)
        b.push_back(s[i]);
      else if (s[i] != '0')
        b.push_back(s[i]);
      i++;
    }
    for (long long int i = 0; i < a.size(); i++) {
      if (a[i] >= '0' and a[i] <= '9')
        mi = max(mi, (long long int)a[i] - '0');
      else
        mi = max(mi, (long long int)(a[i] - 'A' + 10));
    }
    for (long long int i = 0; i < b.size(); i++) {
      if (b[i] >= '0' and b[i] <= '9')
        mi = max(mi, (long long int)b[i] - '0');
      else
        mi = max(mi, (long long int)(b[i] - 'A' + 10));
    }
    vector<long long int> v;
    for (long long int i = mi + 1;; i++) {
      long long int x = a.size(), h = 0, min = 0, j = 0;
      while (x > 0) {
        if (a[a.size() - x] >= '0' and a[a.size() - x] <= '9')
          h = h + biexp(i, x - 1) * (a[a.size() - x] - '0');
        else
          h = h + biexp(i, x - 1) * (a[a.size() - x] - 'A' + 10);
        x--;
      }
      x = b.size();
      while (x > 0) {
        if (b[b.size() - x] >= '0' and b[b.size() - x] <= '9')
          min = min + biexp(i, x - 1) * (b[b.size() - x] - '0');
        else
          min = min + biexp(i, x - 1) * (b[b.size() - x] - 'A' + 10);
        x--;
      }
      if (h > 23 or min > 59)
        break;
      else
        v.push_back(i);
      if (v.size() > 100) break;
    }
    if (v.size() > 100)
      cout << -1;
    else if (v.size() == 0) {
      cout << 0;
    } else {
      for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
    }
  }
  return 0;
}
