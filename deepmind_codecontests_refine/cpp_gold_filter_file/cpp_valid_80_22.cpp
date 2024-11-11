#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int inf = 9 * 1e18;
const long long maxn = 2e5 + 100;
long long pow(long long a, long long b) {
  if (b < 0) return 0LL;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long binpow(long long a, long long b, long long m) {
  if (b < 0) return 0LL;
  if (a <= 0) return 0LL;
  a %= m;
  long long ans = 1LL;
  while (b) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
long long modinv(long long n) { return binpow(n, mod - 2, mod); }
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
void modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    int res = (x % m + m) % m;
    cout << "Modular multiplicative inverse is " << res;
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
const int MAXN = 1.1e6;
int spf[MAXN];
void sieve() {
  for (int i = 1; i < MAXN; i++) spf[i] = 1;
  for (int i = 2; i * i < MAXN; i++) {
    for (int j = i * i; j < MAXN; j += i * i) spf[j] = i;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long getClosest(long long val1, long long val2, long long target) {
  if (target - val1 >= val2 - target)
    return val2;
  else
    return val1;
}
long long findClosest(vector<long long> arr, long long n, long long target) {
  if (target <= arr[0]) return arr[0];
  if (target >= arr[n - 1]) return arr[n - 1];
  long long i = 0, j = n, mid = 0;
  while (i < j) {
    mid = (i + j) / 2;
    if (arr[mid] == target) return arr[mid];
    if (target < arr[mid]) {
      if (mid > 0 && target > arr[mid - 1])
        return getClosest(arr[mid - 1], arr[mid], target);
      j = mid;
    } else {
      if (mid < n - 1 && target < arr[mid + 1])
        return getClosest(arr[mid], arr[mid + 1], target);
      i = mid + 1;
    }
  }
  return mid;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool sol = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      sol = 1;
      if (i >= n / 2) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
        break;
      } else {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << "\n";
        break;
      }
    }
  }
  if (!sol) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
