#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  if (s == "0") {
    cout << 0 << endl;
    return 0;
  }
  if (s == "10") {
    cout << 1 << endl;
    return 0;
  }
  int cnt = 0;
  for (auto e : s) {
    if (e == '0') cnt++;
  }
  if (cnt == (int)s.size() - 1) {
    if (cnt % 2 == 0)
      cout << s.size() / 2 << endl;
    else
      cout << (cnt / 2) + 1 << endl;
  } else {
    cout << ((s.size() - 1) / 2) + 1 << endl;
  }
  return 0;
}
