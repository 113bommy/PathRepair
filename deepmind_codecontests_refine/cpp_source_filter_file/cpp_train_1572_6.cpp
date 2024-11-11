#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000005;
const long long INF = 0xffffffff;
long long a[maxn];
int main() {
  long long n;
  while (cin >> n) {
    fill(a, a + maxn, 0);
    for (long long i = 1; i <= 2 * n; ++i) {
      cin >> a[i];
    }
    sort(a, a + 2 * n + 1);
    long long min1 = INF;
    long long min2 = INF;
    long long x1, x2, y1, y2;
    x1 = a[1], x2 = a[n];
    y1 = a[n + 1], y2 = a[2 * n];
    min1 = (x2 - x1) * (y2 - y1);
    x1 = a[1], x2 = a[2 * n];
    for (long long i = 2, j = i + n - 1; j < 2 * n; ++i, ++j) {
      min2 = min((x2 - x1) * (a[j] - a[i]), min2);
    }
    long long m = min(min1, min2);
    cout << m << endl;
  }
}
