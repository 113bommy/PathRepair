#include <bits/stdc++.h>
using namespace std;
void fun() {
  string s, t;
  long long c, n, k, m, i, j, x, y;
  cin >> n >> m >> k;
  long long a[n], b[n], l[m], r[m], d[m], q[m], sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    a[i] = 0;
  }
  for (i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> d[i];
    q[i] = 0;
  }
  for (i = 0; i < k; i++) {
    cin >> x >> y;
    q[x - 1]++;
    if (y < n) q[y]--;
  }
  for (i = 0; i < m; i++) {
    sum += q[i];
    a[l[i] - 1] += d[i] * sum;
    if (r[i] < n) {
      a[r[i]] -= d[i] * sum;
    }
  }
  sum = 0;
  for (j = 0; j < n; j++) {
    sum += a[j];
    cout << sum + b[j] << " ";
  }
}
int main() {
  long long i, t = 1;
  for (i = 0; i < t; i++) fun();
}
