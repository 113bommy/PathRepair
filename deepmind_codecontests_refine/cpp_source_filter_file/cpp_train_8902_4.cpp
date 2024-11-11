#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ; ";
  err(++it, args...);
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<int, int> mp;
  vector<int> v;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int start = 1;
  bool paisi = true;
  while (start >= 1 && start <= n) {
    if (mp[start] == 1) {
      paisi = false;
      break;
    }
    int keep = start;
    char c = s[start - 1];
    if (c == '>') {
      start += v[start - 1];
    } else
      start -= v[start - 1];
    mp[keep]++;
  }
  if (paisi)
    cout << "FINITE" << endl;
  else
    cout << "INFINFTE" << endl;
  return 0;
}
