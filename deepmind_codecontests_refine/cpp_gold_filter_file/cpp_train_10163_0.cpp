#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int t;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 1;
    return;
  }
  n--;
  n *= 2;
  cout << n << " " << 2 << endl;
  cout << 1 << " " << 2;
}
