#include <bits/stdc++.h>
using namespace std;
int rastavi(int n) {
  int sol = 0;
  while (n) {
    if (n % 10 == 4 || n % 10 == 7) ++sol;
    n /= 10;
  }
  return sol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (rastavi(a) <= k) ++sol;
  }
  cout << sol << '\n';
}
