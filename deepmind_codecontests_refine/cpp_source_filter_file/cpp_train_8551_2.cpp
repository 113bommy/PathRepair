#include <bits/stdc++.h>
using namespace std;
long long a[200005];
pair<long long, long long> p[200005];
long long m = 1;
long long Euclid(long long nA, long long nB) {
  if (nB == 0)
    return nA;
  else
    return Euclid(nB, nA % nB);
}
int factor(int n) {
  int count = 1, num = sqrt(n);
  a[0] = n;
  for (int i = 2; i < num; i++) {
    if (!(n % i)) {
      a[count++] = i;
      a[count++] = n / i;
    }
  }
  if (n == (num * num)) a[count++] = num;
  return count;
}
int main() {
  long long c, b;
  cin >> c >> b;
  int z = 1;
  if (c * b / Euclid(c, b) == max(c, b)) {
    cout << 0;
    return 0;
  }
  p[0].first = (c + b) / Euclid(c, b);
  p[0].second = 0;
  long long d = abs(c - b);
  long long g = factor(d);
  for (int i = 0; i < g; i++) {
    long long c1 = c + a[i] - c % a[i];
    long long b1 = b + a[i] - c % a[i];
    p[z].first = c1 * b1 / Euclid(c1, b1);
    p[z].second = a[i] - c % a[i];
    z++;
  }
  z = z - 1;
  sort(p, p + z);
  cout << p[0].second;
  return 0;
}
