#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  cout << (n / 2) << '\n';
  for (long long i = 0; i < n / 2 - 1; i++) cout << "2 ";
  cout << ((n & 1) + 2) << '\n';
  return 0;
}
