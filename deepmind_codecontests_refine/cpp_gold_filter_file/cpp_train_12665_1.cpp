#include <bits/stdc++.h>
using namespace std;
long long zero = 0;
long long one = 1;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long expo(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (1ll * res * x) % 1000000007;
    y = y >> 1;
    x = (1ll * x * x) % 1000000007;
  }
  return res;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
bool prime(long long n) {
  long long i;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool sor(const pair<long long, pair<long long, long long>> &a,
         const pair<long long, pair<long long, long long>> &b) {
  return (a.first > b.first);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  int arr[100][100] = {0};
  char s[n][n];
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)n; j++) {
      cin >> s[i][j];
      if (s[i][j] == '.') {
        int z = j;
        while (z >= 0 && s[i][z] == '.') {
          z--;
          if ((j - z) == k) {
            z++;
            while (z != j + 1) {
              arr[i][z]++;
              z++;
            }
            break;
          }
        }
        int y = i;
        while (y >= 0 && s[y][j] == '.') {
          y--;
          if ((i - y) == k) {
            y++;
            while (y != i + 1) {
              arr[y][j]++;
              y++;
            }
            break;
          }
        }
      }
    }
  }
  int f, g, max1 = INT_MIN;
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)n; j++) {
      if (arr[i][j] > max1) {
        f = i;
        g = j;
        max1 = arr[i][j];
      }
    }
  }
  cout << f + 1 << " " << g + 1;
}
