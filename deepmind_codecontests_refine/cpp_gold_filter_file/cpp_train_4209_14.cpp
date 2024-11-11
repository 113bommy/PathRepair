#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
using namespace std;
void vok() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n == 5 or n == 7) return true;
  if (n % 2 == 0 or n % 5 == 0 or n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 or n % (i + 2) == 0) return false;
  }
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return ((a * b) / gcd(a, b));
}
vector<long long int> pp;
void gen() {
  vector<bool> prime(33000, true);
  prime[0] = prime[1] = false;
  for (int p = 0; p * p <= 33000; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= 33000; i += p) prime[i] = false;
    }
  }
  for (int i = 0; i < 33000; i++)
    if (prime[i]) pp.push_back(i);
}
long long int find(vector<int>& A, int n) {}
void solve() {
  long long int n, m, x, y, a, b, c, d, k, z;
  long long int mx = -1;
  long long int mi = INT_MAX;
  a = b = x = y = k = c = z = 0;
  long long int ans = 0, res = 0;
  cin >> n;
  string str;
  cin >> k;
  vector<int> A;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 0)
      x++;
    else
      y++;
    A.push_back(a);
  }
  for (int i = 0; i < k; i++) {
    a = 0;
    b = 0;
    for (int j = i; j < n; j += k) {
      if (A[j] % 2 == 0)
        a++;
      else
        b++;
    }
    ans += min(a, b);
  }
  cout << ans << endl;
}
int main() {
  vok();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
