#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long int pow1(long long int n, long long int p) {
  if (p == 0) return 1;
  long long int x = pow1(n, p / 2);
  x = (x * x) % 1000000007;
  if (p % 2 == 0)
    return x % 1000000007;
  else
    return (x * n) % 1000000007;
}
long long int pd(long long int x, long long int y) {
  if (x % y == 0)
    return x / y;
  else
    return x / y + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  while (t--) {
    long long int x, y, n, m, j, k, i;
    cin >> n >> x >> y;
    if (n / 2 == x || n / 2 + 1 == x || n / 2 == y || n / 2 + 1 == y)
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
  }
  return 0;
}
