#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long base = 1e9;
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long N = 1e5 + 10;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  a--;
  b--;
  long long k = 1;
  while ((a /= 2) != (b /= 2)) {
    n /= 2;
    k++;
  }
  if (n == 2)
    cout << "Final" << endl;
  else
    cout << k << endl;
  return 0;
}
