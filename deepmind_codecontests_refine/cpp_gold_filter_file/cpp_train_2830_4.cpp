#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++)
    if (s[i] != t[i]) {
      if (s[i] == 'a')
        a.push_back(i);
      else
        b.push_back(i);
    }
  if (a.size() % 2 != b.size() % 2) {
    cout << -1 << endl;
    return 0;
  }
  if (a.size() % 2 == 0 && b.size() % 2 == 0)
    cout << (a.size() / 2 + b.size() / 2) << endl;
  else
    cout << (a.size() / 2 + b.size() / 2 + 2) << endl;
  if (a.size() >= 2) {
    for (int i = 0; i + 1 < a.size(); i += 2)
      cout << a[i] + 1 << ' ' << a[i + 1] + 1 << endl;
  }
  if (b.size() >= 2) {
    for (int i = 0; i + 1 < b.size(); i += 2)
      cout << b[i] + 1 << ' ' << b[i + 1] + 1 << endl;
  }
  if (a.size() % 2 != 0) {
    cout << a.back() + 1 << ' ' << a.back() + 1 << endl;
    cout << a.back() + 1 << ' ' << b.back() + 1 << endl;
  }
  return 0;
}
