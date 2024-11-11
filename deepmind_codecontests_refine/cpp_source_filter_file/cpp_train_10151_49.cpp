#include <bits/stdc++.h>
using namespace std;
unsigned long long int i, j, m, c, ok, q, maxi = -1, divi, p, n1, n2, first,
                                          second, g, a, b, n, mod, k, ul, poz,
                                          pozy, w[10], mini = 100000000;
int v[1000000], d[500][500];
long long int sum;
char s[1000000], ss[10000], z;
vector<int> r;
string aa;
int isprime(int first) {
  if (first == 2) return 1;
  if (first < 2) return 0;
  if (first % 2 == 0) return 0;
  for (int i = 3; i * i <= first; i += 2)
    if (first % i == 0) return 0;
  return 1;
}
unsigned long long int divizor(unsigned long long int a,
                               unsigned long long int b) {
  unsigned long long int r;
  r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;
  m = divizor(a, b);
  if (a < b) swap(a, b);
  a /= m;
  if (a <= n / b) {
    m = a * b;
    divi += n / m * b;
  } else
    m = 5000000000000000000;
  divi += min(b - 1, n % m);
  m = divizor(divi, n);
  cout << divi / m << "/" << n / m;
  return 0;
}
