#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, ans = 0, c = 1;
  cin >> n;
  string s, s1;
  cin >> s;
  vector<long long> v;
  if (s[0] == '0') v.push_back(0);
  for (long long i = 1; i < n; i++) {
    if (s[i - 1] == s[i])
      c++;
    else {
      v.push_back(c);
      c = 1;
    }
  }
  v.push_back(c);
  if (v.size() == 1) {
    cout << s << endl;
    return;
  }
  if (v[0] == 0) {
    if (v.size() == 3) {
      cout << s << endl;
      return;
    }
    for (long long i = 0; i < v[1]; i++) cout << 0;
    if (v.size() % 2 == 0)
      cout << 0;
    else {
      cout << 0;
      for (long long i = 0; i < v[v.size() - 1]; i++) cout << 1;
    }
  } else {
    if (v.size() % 2 == 0)
      cout << 0;
    else {
      cout << 0;
      for (long long i = 0; i < v[v.size() - 1]; i++) cout << 1;
    }
  }
  cout << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long query = 1;
  cin >> query;
  while (query--) {
    solve();
  }
}
