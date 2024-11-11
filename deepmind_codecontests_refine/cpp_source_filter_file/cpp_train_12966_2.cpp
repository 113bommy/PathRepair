#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
long long n;
int x, y, m;
bool c[MAX_N], r[MAX_N];
long long f(long long a, long long b) {
  return n * n - (a * n + b * n - a * b);
}
int main() {
  cin >> n >> m;
  long long a = 0, b = 0;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (!r[x]) {
      a++;
      r[x] = true;
    }
    if (!c[y]) {
      b++;
      c[y] = true;
    }
    if (i != m - 1)
      cout << f(a, b) << " ";
    else
      cout << f(a, b) << endl;
  }
  return 0;
}
