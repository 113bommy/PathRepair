#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
void read(vector<long long int> &a, int n) {
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
}
bool check(string s) {
  long long int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') cnt++;
    if (cnt > 1 || (s[i] != '1' && s[i] != '0')) return false;
  }
  return true;
}
bool fine = 0;
vector<long long int> a;
long long int n, m;
void solve() {
  cin >> n;
  string ans, temp = "1";
  bool ok = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (check(s) && s.size() > 1) {
      for (int j = 0; j < s.size() - 1; j++) ans.push_back('0');
    }
    if (!check(s)) temp = s;
    if (s == "0") ok = true;
  }
  if (ok)
    cout << "0";
  else {
    cout << temp + ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fine) {
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
  } else
    solve();
  return 0;
}
