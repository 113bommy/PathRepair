#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
const long long minf = -2e18;
const long long modulo = 1e9 + 7;
template <typename T>
void printArray(T a[], int n) {
  for (int i = 0; i < n; i++) cerr << a[i] << " ";
  cerr << endl;
}
long long power(long long x, long long y, long long mod) {
  long long ans = 1;
  x = x % mod;
  while (y) {
    if (y & 1) ans = (x * ans) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
vector<bool> isprime(50002, true);
void sieve(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (isprime[i] == true) {
      for (int j = i * 2; j <= n; j += i) {
        isprime[j] = false;
      }
    }
  }
}
long long fibonacci(int n, long long a, long long b) {
  for (int i = 2; i < n; i++) {
    long long c = (a + b) % modulo;
    a = b % modulo;
    b = c % modulo;
  }
  return b % modulo;
}
int binsearch(vector<long long> a, int n, int x) {
  int low = 0, high = n - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (a[mid] == x) {
      return mid;
      break;
    } else if (a[mid] > x) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> occ(1000, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (occ[a[i]] == 0) {
      occ[a[i]] = 1;
      ans.push_back(a[i]);
    }
  }
  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  return 0;
}
