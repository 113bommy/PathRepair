#include <bits/stdc++.h>
using namespace std;
long long mcd(long long a, long long b) {
  if (b > a) {
    long long aux = b;
    b = a;
    a = aux;
  }
  if (b == 0)
    return a;
  else
    return mcd(b, a % b);
}
long long mcm(long long a, long long b) { return a * b / mcd(a, b); }
int main() {
  long long n, m, g, h;
  cin >> n >> m;
  bool hb[n];
  bool hg[m];
  for (long long i = 0; i < n; i++) hb[i] = false;
  for (long long i = 0; i < m; i++) hg[i] = false;
  cin >> g;
  while (g) {
    cin >> h;
    hb[h] = true;
    g--;
  }
  cin >> g;
  while (g) {
    cin >> h;
    hg[h] = true;
    g--;
  }
  long long d = mcm(n, m) * 2;
  for (long long i = 0; i < d; i++) {
    if (hb[i % n] || hg[i % m]) {
      hb[i % n] = hg[i % m] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (hb[i] == false) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (hg[i] == false) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
