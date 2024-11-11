#include <bits/stdc++.h>
using namespace std;
long long int xo(long long int x, long long int y) {
  return (x | y) & (~x | ~y);
}
void swapp(long long int* a, long long int* b) {
  long long int t = *a;
  *a = *b;
  *b = t;
}
long long int bin_Expo(long long int x, long long int n) {
  if (x == 0) return 0;
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return bin_Expo(x * x, n / 2);
  else
    return x * bin_Expo(x * x, (n - 1) / 2);
}
long long int mod_Expo(long long int x, long long int n, long long int M) {
  if (x == 0) return 0;
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return mod_Expo((x * x) % M, n / 2, M);
  else
    return (x * mod_Expo((x * x) % M, (n - 1) / 2, M)) % M;
}
bool prime_check(long long int x) {
  bool prime = (x >= 2);
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      prime = false;
      break;
    }
  }
  return prime;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long int n, k, i, j, ans, ans1, pos, maxir, maxic, mini, l, h, mid, m,
        c, n1, n2;
    cin >> n;
    string a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    k = 1;
    c = 0;
    for (long long int i = 0; i < n - 1; i++) {
      m = 1;
      for (long long int j = i + 1; j < n; j++) {
        for (long long int x = 0; x < n; x++) {
          if (a[i][x] != a[j][x]) c = 1;
        }
        if (c == 0) {
          m++;
        }
        c = 0;
      }
      k = max(k, m);
    }
    cout << k;
  }
  return 0;
}
