#include <bits/stdc++.h>
using namespace std;
long long hi = 1000003;
long long po(long long a) {
  if (a <= 0) return 1;
  long long x = po(a / 2);
  x = (x * x) % hi;
  if (a % 2) x = (3 * x) % hi;
  return x;
}
int main() {
  int n;
  scanf("%d", &n);
  cout << po(n - 1);
  return 0;
}
