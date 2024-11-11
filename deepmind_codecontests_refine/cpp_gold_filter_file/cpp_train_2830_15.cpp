#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int cnt = 0, c = 0;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      c++;
      if (s[i] == 'a')
        a.push_back(i);
      else if (s[i] == 'b')
        b.push_back(i);
    }
  }
  if (a.size() % 2 != b.size() % 2 || c % 2 != 0) {
    cout << -1;
    return 0;
  }
  cnt += (a.size() / 2) + (b.size() / 2) + 2 * (a.size() % 2);
  cout << cnt << endl;
  int n1 = a.size(), n2 = b.size(), x = 0, y = 0;
  for (int i = 0; i < n1 - 1; i += 2) {
    cout << a[i] + 1 << " " << a[i + 1] + 1 << " " << endl;
  }
  for (int i = 0; i < n2 - 1; i += 2)
    cout << b[i] + 1 << " " << b[i + 1] + 1 << " " << endl;
  if (n1 % 2) x = a[n1 - 1];
  if (n2 % 2) y = b[n2 - 1];
  if (x != 0 || y != 0) {
    cout << x + 1 << " " << x + 1 << endl;
    cout << x + 1 << " " << y + 1 << endl;
  }
  return 0;
}
