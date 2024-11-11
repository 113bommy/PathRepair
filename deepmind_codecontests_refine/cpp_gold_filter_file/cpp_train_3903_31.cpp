#include <bits/stdc++.h>
using namespace std;
void solve() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin >> n;
  if (n == "4") {
    cout << "1";
    return 0;
  }
  if (n == "7") {
    cout << "2";
    return 0;
  }
  vector<string> a;
  a.push_back("4");
  a.push_back("7");
  int i = 1;
  while (1) {
    string g = a[(i - 1) / 2];
    if (i % 2 != 0) g += '4';
    if (i % 2 == 0) g += '7';
    if (g == n) {
      cout << i + 2;
      break;
    }
    a.push_back(g);
    i++;
  }
}
