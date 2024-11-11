#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
long long MAX = 1e9;
long long MOD = 1e9 + 7;
long long Mod = 1e9 + 7;
double EPS = 0.0001;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
int main() {
  int wait;
  long long n, k;
  int prin = 0;
  scanf("%d", &n);
  scanf("%d", &k);
  long long check = k * (k - 1);
  if (check < n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (long long i = 1; i < k + 1; i++) {
    for (long long j = i + 1; j < k + 1; j++) {
      cout << i << " " << j << endl;
      prin++;
      if (prin == n) return 0;
      cout << j << " " << i << endl;
      prin++;
      if (prin == n) return 0;
    }
  }
  return 0;
}
