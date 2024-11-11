#include <bits/stdc++.h>
using namespace std;
const int OO = 0xfffffff;
const int _OO = -1 * OO;
const double EPS = (1e-9);
const double pi = 3.14159265;
using namespace std;
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[8] = {1, -1, 0, 1, -1, 1, -1, 0};
long long gcd(long long a, long long b) {
  if (a == 0) return 0;
  return gcd(b % a, a) + b / a;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) - 1 << endl;
  }
  return 0;
}
