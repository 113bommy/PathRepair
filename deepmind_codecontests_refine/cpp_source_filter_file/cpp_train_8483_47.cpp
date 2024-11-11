#include <bits/stdc++.h>
using namespace std;
void init_code() {}
bool cmp(pair<char, int>& a, pair<char, int>& b) { return a.second > b.second; }
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 1) {
    cout << "0 0" << endl;
    return;
  } else {
    if (a == b) {
      cout << a << " "
           << "0" << endl;
      return;
    }
    if (a > b) {
      cout << b << " " << ((a - b) / 2) << endl;
      return;
    }
    if (a < b) {
      cout << a << " " << ((b - a) / 2) << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
