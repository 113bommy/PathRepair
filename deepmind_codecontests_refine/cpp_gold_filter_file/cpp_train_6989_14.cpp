#include <bits/stdc++.h>
using namespace std;
inline void Boost() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long int MX = 1000000;
int main() {
  Boost();
  long long int k;
  cin >> k;
  int n = 2000;
  cout << n << "\n-1 ";
  long long int s = k + n;
  for (int i = 1; i < n; ++i) {
    cout << min(MX, s) << " ";
    s -= MX;
    s = max(0LL, s);
  }
  return 0;
}
