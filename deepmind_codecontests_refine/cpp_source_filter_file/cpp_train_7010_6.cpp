#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a > b); }
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main(void) {
  int n, m;
  cin >> n >> m;
  long long int an1 = 0, an2 = 0;
  if (n == 0) {
    cout << "Impossible";
    return 0;
  }
  if (m > n)
    an1 = m;
  else
    an1 = n;
  if (m == 0 || m == 1)
    an2 = an1;
  else
    an2 = m + n - 1;
  cout << an1 << " " << an2;
  return 0;
}
