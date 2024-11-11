#include <bits/stdc++.h>
using namespace std;
string ys = "YES", no = "NO", st;
int di[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dj[8] = {0, -1, 0, 1, 1, 1, -1, -1};
const int N = 1.5 * 10000000 + 16;
const long long int OO = 1e18;
long long int mod = 1e9 + 7;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  fast();
  int q;
  q = 1;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long h = (a * b) / gcd(a, b);
    int d = (h - 1) / a, m = (h - 1) / b;
    if (d < m)
      d++;
    else if (m < d)
      m++;
    if (d > m)
      return cout << "Dasha"
                  << "\n",
             0;
    if (m > d)
      return cout << "Masha"
                  << "\n",
             0;
    return cout << "Equal"
                << "\n",
           0;
  }
}
