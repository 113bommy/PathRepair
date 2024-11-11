#include <bits/stdc++.h>
using namespace std;
long long a[300000];
long long b[300000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i;
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; i < n - 2; i++) {
    if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
      a[i]++;
    }
  }
  vector<char> v;
  for (i = 0; i < n; i++) {
    if (a[i] == 0) v.push_back(s[i]);
  }
  long long t = 0;
  for (i = 0; i < v.size() - 1; i++) {
    if (i % 2 == t && (v[i] == v[i + 1])) {
      b[i]++;
      if (t == 0)
        t = 1;
      else
        t = 0;
    }
  }
  vector<char> vv;
  for (i = 0; i < v.size(); i++) {
    if (b[i] == 0) vv.push_back(v[i]);
  }
  long long sz = n - vv.size();
  if (vv.size() % 2) {
    vv.pop_back();
    sz++;
  }
  cout << sz << "\n";
  if (vv.empty() == 0) {
    for (i = 0; i < vv.size(); i++) {
      cout << vv[i];
    }
  }
  return 0;
}
