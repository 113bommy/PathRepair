#include <bits/stdc++.h>
using namespace std;
int abso(int a) { return (a < 0) ? a * -1 : a; }
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n / 4; i++) {
    if ((n - i * 4) % 7 == 0) {
      int x = (n - i * 4) / 7;
      for (int j = 0; j < i; j++) {
        cout << "4";
      }
      for (int j = 0; j < x; j++) {
        cout << "7";
      }
      puts("");
      return;
    }
  }
  cout << "-1" << endl;
}
int main() {
  solve();
  return 0;
}
