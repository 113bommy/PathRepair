#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
  if (a.length() < b.length())
    return true;
  else
    return false;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "1 1";
    return 0;
  }
  vector<string> a;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  string s;
  cin >> s;
  bool e1 = true;
  int len = 0;
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++) {
    string g = a[i];
    if (g.length() == s.length() && e1) {
      int le = i + 1;
      le += (i / k) * 5;
      cout << le << " ";
      e1 = false;
    }
    if (g.length() > s.length()) {
      len = i;
      len += ((len - 1) / k) * 5;
      cout << len;
      return 0;
    }
  }
  len += n + (((n - 1) / k) * 5);
  cout << len;
}
