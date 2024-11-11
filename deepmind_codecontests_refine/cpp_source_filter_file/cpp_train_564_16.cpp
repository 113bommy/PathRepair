#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  string a;
  long long n = s.size(), m = t.size(), flag = -1;
  if (n > m) {
    long long j = 0, i;
    for (i = 0; i < n && j < m; i++) {
      if (s[i] == t[j]) {
        j++;
      }
    }
    if (j == m) {
      flag = 0;
    } else {
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      long long k = 0, i;
      for (i = 0; i < n && j < m; i++) {
        if (s[i] == t[k]) {
          k++;
        }
      }
      if (k == m)
        flag = 2;
      else
        flag = 3;
    }
  } else if (n < m)
    flag = 3;
  else {
    if (s == t)
      flag = 1;
    else {
      sort(s.begin(), s.end());
      sort(t.begin(), t.end());
      if (s == t)
        flag = 1;
      else
        flag = 3;
    }
  }
  if (flag == 0)
    cout << "automation";
  else if (flag == 1)
    cout << "array";
  else if (flag == 2)
    cout << "both";
  else
    cout << "need tree";
}
