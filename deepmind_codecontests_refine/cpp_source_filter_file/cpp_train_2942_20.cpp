#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void pre() {}
void solve() {
  long long n;
  cin >> n;
  if (n <= 2) {
    cout << 1 << "\n";
    return;
  } else if (n <= 4) {
    cout << 2 << "\n";
    return;
  } else {
    cout << (n) / 2 << "\n";
    return;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
