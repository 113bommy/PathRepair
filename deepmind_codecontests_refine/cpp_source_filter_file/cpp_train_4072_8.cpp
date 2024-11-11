#include <bits/stdc++.h>
using namespace std;
const long long int modulo = 1e9 + 7;
void add(long long int &a, long long int b) { a = (a + b) % modulo; }
const int limit = 300005;
long long int eleva(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return eleva(b * b % modulo, e / 2);
  return b * eleva(b * b % modulo, e / 2) % modulo;
}
long long int inverse(long long int x) { return eleva(x, modulo - 2); }
int n;
int a[limit];
long long int fact[limit];
long long int factinv[limit];
int howmany[limit];
long long int ways[limit][7];
long long int combi(int n, int k) {
  if (k < 0 or n < k) return 0;
  return fact[n] * factinv[k] % modulo * factinv[n - k] % modulo;
}
int main() {
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < limit; i++) {
    fact[i] = fact[i - 1] * i % modulo;
    factinv[i] = factinv[i - 1] * inverse(i) % modulo;
  }
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    howmany[a[i]]++;
  }
  for (int x = limit - 1; x >= 1; x--) {
    int multiples = 0;
    for (int y = x; y < limit; y += x) multiples += howmany[y];
    if (not multiples) continue;
    for (int i = 1; i < 7; i++) {
      long long int waysabove = 0;
      for (int y = x + x; y < limit; y += x) add(waysabove, ways[y][i]);
      ways[x][i] = (combi(multiples, i) - waysabove) % modulo;
    }
  }
  for (int i = 1; i < 7; i++) {
    if (ways[1][i]) {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}
