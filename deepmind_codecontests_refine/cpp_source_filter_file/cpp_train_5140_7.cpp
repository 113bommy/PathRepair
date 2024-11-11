#include <bits/stdc++.h>
using namespace std;
long long i, j, k, x, y, z, n, m;
long long max(long long x, int y) { return max(x, (long long)y); }
long long dcsl(long long x) { return x * (x + 1) / 2; }
long long ul(long long t) {
  long long X = x, Y = y;
  long long s = max(t - Y + 1, 0) * Y + max(t - X + 1, 0) * X -
                max(t - Y + 1, 0) * max(t - X + 1, 0);
  if (t < min(X, Y))
    return (s + dcsl(t + 1));
  else if (t < max(X, Y))
    return (s + dcsl(min(X, Y)));
  else if (t < X + Y - 2)
    return (s + dcsl(min(X, Y) - (t - max(X, Y) + 1)));
  else
    return X * Y;
}
long long ur(long long t) {
  long long X = x, Y = n - y + 1;
  long long s = max(t - Y + 1, 0) * Y + max(t - X + 1, 0) * X -
                max(t - Y + 1, 0) * max(t - X + 1, 0);
  if (t < min(X, Y))
    return (s + dcsl(t + 1));
  else if (t < max(X, Y))
    return (s + dcsl(min(X, Y)));
  else if (t < X + Y - 2)
    return (s + dcsl(min(X, Y) - (t - max(X, Y) + 1)));
  else
    return X * Y;
}
long long dr(long long t) {
  long long X = n - x + 1, Y = n - y + 1;
  long long s = max(t - Y + 1, 0) * Y + max(t - X + 1, 0) * X -
                max(t - Y + 1, 0) * max(t - X + 1, 0);
  if (t < min(X, Y))
    return (s + dcsl(t + 1));
  else if (t < max(X, Y))
    return (s + dcsl(min(X, Y)));
  else if (t < X + Y - 2)
    return (s + dcsl(min(X, Y) - (t - max(X, Y) + 1)));
  else
    return X * Y;
}
long long dl(long long t) {
  long long X = n - x + 1, Y = y;
  long long s = max(t - Y + 1, 0) * Y + max(t - X + 1, 0) * X -
                max(t - Y + 1, 0) * max(t - X + 1, 0);
  if (t < min(X, Y))
    return (s + dcsl(t + 1));
  else if (t < max(X, Y))
    return (s + dcsl(min(X, Y)));
  else if (t < X + Y - 2)
    return (s + dcsl(min(X, Y) - (t - max(X, Y) + 1)));
  else
    return X * Y;
}
long long tot(long long t) {
  return dl(t) + dr(t) + ur(t) + ul(t) - min(t + 1, x) - min(t + 1, y) -
         min(t + 1, n - x + 1) - min(t + 1, n - y + 1) + 1;
}
int main() {
  scanf("%d%d%d%d", &n, &x, &y, &m);
  long long high = n, low = 0, mid;
  while (high > low) {
    mid = (high + low) / 2;
    if (tot(mid) >= m)
      high = mid;
    else
      low = mid + 1;
  }
  printf("%d\n", high);
  return 0;
}
