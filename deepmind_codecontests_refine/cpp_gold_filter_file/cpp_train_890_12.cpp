#include <bits/stdc++.h>
const long double eps = 1e-9;
const long double pi = acos(-1);
using namespace std;
char temp[2225];
int ar[] = {0, 0, -1, 1, 1, 1, -1, -1};
int ac[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  int lcm = n * m / gcd(n, m);
  cout << k / lcm;
  return 0;
}
