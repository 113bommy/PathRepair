#include <bits/stdc++.h>
using namespace std;
long long int n, k, x;
string a = "abacaba";
bool check(string s, long long int i) {
  for (long long int j = 0; j < n; j++) {
    if (s[j] == '?') s[j] = 'z';
  }
  for (long long int j = 0; j < 7; j++) {
    s[i + j] = a[j];
  }
  long long int cnt = 0;
  string tmp;
  for (long long int j = 0; j < n - 6; j++) {
    tmp = "";
    for (long long int k = j; k < j + 7; k++) tmp += s[k];
    if (tmp == a) cnt++;
  }
  if (cnt == 1)
    return 1;
  else
    return 0;
}
void solve() {
  cin >> n;
  string s;
  cin >> s;
  vector<long long int> v;
  if (n < 7) {
    cout << "NO\n";
    return;
  }
  string tmp = "";
  long long int cnt = 0;
  for (long long int i = 0; i < n - 6; i++) {
    tmp = "";
    for (long long int j = i; j < i + 7; j++) tmp += s[j];
    if (tmp == a) cnt++;
  }
  if (cnt == 1) {
    cout << "YES\n";
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '?')
        cout << 'z';
      else
        cout << s[i];
    }
    cout << "\n";
    return;
  }
  if (cnt > 1) {
    cout << "NO\n";
    return;
  }
  for (long long int i = 0; i < n - 6; i++) {
    tmp = "";
    for (long long int j = i; j < i + 7; j++) tmp += s[j];
    for (long long int j = 0; j < 7; j++) {
      if (tmp[j] == '?') {
        tmp[j] = a[j];
      }
    }
    if (tmp == a) v.push_back(i);
  }
  if (v.empty()) {
    cout << "NO\n";
    return;
  }
  k = v.size();
  for (long long int i = 0; i < k; i++) {
    if (check(s, v[i])) {
      cout << "YES\n";
      for (long long int i = 0; i < n; i++) {
        if (a[i] == '?') s[i] = 'z';
      }
      for (long long int j = 0; j < 7; j++, v[i]++) {
        s[v[i]] = a[j];
      }
      cout << s << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
