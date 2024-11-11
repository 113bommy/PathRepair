#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, u, r;
vector<int> v;
bool e[100002];
int main() {
  cin >> s >> t;
  n = s.size();
  u = t.size();
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      bool h = 1;
      for (int j = i; j < n; j++)
        if (s[j] != s[j % i]) {
          h = 0;
          break;
        }
      if (h) e[i] = true;
      if (n / i != i) {
        h = 1;
        for (int j = n / i; j < n; j++)
          if (s[j] != s[j % (n / i)]) {
            h = 0;
            break;
          }
        if (h) e[n / i] = 1;
      }
    }
  }
  for (int i = 1; i * i <= u; i++) {
    if (u % i == 0) {
      bool h = 1;
      for (int j = i; j < u; j++)
        if (t[j] != t[j % i]) {
          h = 0;
          break;
        }
      if (h && e[i]) v.push_back(i);
      if (u / i != i) {
        h = 1;
        for (int j = u / i; j < u; j++)
          if (t[j] != t[j % (u / i)]) {
            h = 0;
            break;
            cout << i << " " << j << endl;
          }
        if (h && e[u / i]) v.push_back(u / i);
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    bool h = 1;
    for (int j = 0; j < v[i]; j++)
      if (s[j] != t[j]) h = 0;
    if (h) r++;
  }
  cout << r;
  return 0;
}
