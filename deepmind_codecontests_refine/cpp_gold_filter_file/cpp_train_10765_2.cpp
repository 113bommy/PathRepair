#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v;
  if (n == 0) {
    cout << "O-|-OOOO";
    return 0;
  }
  while (n) {
    string s = "";
    int cur = n % 10;
    if (cur >= 5) {
      s += "-O|";
      cur -= 5;
    } else
      s += "O-|";
    for (int i = 0; i < 5; ++i) {
      if (cur != 0)
        s += "O";
      else
        s += "-";
      cur--;
    }
    v.push_back(s);
    n /= 10;
  }
  for (auto s : v) cout << s << "\n";
  return 0;
}
