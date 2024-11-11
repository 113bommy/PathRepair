#include <bits/stdc++.h>
using namespace std;
void solve() {
  int cant;
  cin >> cant;
  int length = cant;
  bool repeat = true;
  int first_num;
  cin >> first_num;
  while (cant-- >= 1) {
    int num;
    cin >> num;
    if (num != first_num) repeat = false;
  }
  if (repeat)
    cout << length << "\n";
  else
    cout << "1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
