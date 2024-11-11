#include <bits/stdc++.h>
long long i, j;
const int mod = 1000000007;
using namespace std;
void solve() {
  long long n, p = 0, ct = 0, sum = 0, k;
  string s;
  cin >> n;
  if (n == 0)
    cout << "1";
  else if (n % 4 == 1)
    cout << "8";
  else if (n % 4 == 2)
    cout << 4;
  else if (n % 4 == 3)
    cout << 2;
  else
    cout << 6;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    solve();
    cout << "\n";
  }
  return 0;
}
