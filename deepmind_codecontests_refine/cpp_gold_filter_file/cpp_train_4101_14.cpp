#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int ip[100001];
unsigned int m, x;
int n, k, i;
void mask() {
  int i, l = 0, k;
  k = n;
  for (i = 0; i < n; i++) ip[i] = ip[i] & m;
  for (i = 1; i < n; i++) {
    if (ip[i] == ip[i - 1])
      k--;
    else {
      l++;
      ip[l] = ip[i];
    }
  }
  n = k;
}
int main() {
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ip[i] = a;
    ip[i] <<= 8;
    ip[i] += b;
    ip[i] <<= 8;
    ip[i] += c;
    ip[i] <<= 8;
    ip[i] += d;
  }
  m = 4294967295;
  sort(ip, ip + n);
  if (n == k) x++;
  do {
    m <<= 1;
    mask();
    if (n == k && m) x = 1;
  } while (n >= k && m);
  if (x) {
    m >>= 1;
    m += 2147483648;
    d = m % 256;
    m /= 256;
    c = m % 256;
    m /= 256;
    b = m % 256;
    m /= 256;
    a = m % 256;
    printf("%d.%d.%d.%d", a, b, c, d);
  } else
    printf("-1");
  return 0;
}
