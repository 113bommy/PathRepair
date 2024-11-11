#include <bits/stdc++.h>
using namespace std;
long long int cost(long long int x[], long long int a, long long int n,
                   long long int r, long long int m, long long int val) {
  long long int pos = 0;
  long long int neg = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] > val)
      pos += x[i] - val;
    else
      neg += val - x[i];
  }
  if (a + r < m)
    return a * neg + r * pos;
  else {
    if (pos > neg)
      return neg * m + (pos - neg) * r;
    else
      return pos * m + (neg - pos) * a;
  }
}
long long int binary(long long int x[], long long int a, long long int n,
                     long long int r, long long int m, long long int min,
                     long long int max) {
  if (min > max)
    return -1;
  else {
    long long int mid = (min + max) / 2;
    long long int q = cost(x, a, n, r, m, mid);
    long long int w = cost(x, a, n, r, m, mid - 1);
    long long int e = cost(x, a, n, r, m, mid + 1);
    if (q <= w && q <= e) {
      return q;
    } else if (w > q && q > e)
      return binary(x, a, n, r, m, mid + 1, max);
    else
      return binary(x, a, n, r, m, min, mid - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, a, r, m;
  cin >> n >> a >> r >> m;
  long long int *x = new long long int[n];
  long long int min = 100000001;
  long long int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] > max) max = x[i];
    if (x[i] < min) min = x[i];
  }
  long long int sum = binary(x, a, n, r, m, min, max);
  cout << sum << "\n";
}
