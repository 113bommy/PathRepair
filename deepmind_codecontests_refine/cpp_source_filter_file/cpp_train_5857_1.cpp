#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    if (n >= r)
      cout << (long long)r * (r + 1) / 2 << endl;
    else
      cout << (long long)n * (n - 1) / 2 + 1 << endl;
  }
  return 0;
}
