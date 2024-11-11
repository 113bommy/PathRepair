#include <bits/stdc++.h>
using namespace std;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long int nCmmod(long long int n, long long int m, long long int mod) {
  vector<long long int> a(200001, 1);
  for (__typeof(1) i = 1; i < 200001; i += 1) {
    a[i] = (a[i - 1] * i) % mod;
  }
  long long int p = 1;
  p = (p * a[n]) % mod;
  p = (p * modInverse(a[m], mod)) % mod;
  p = (p * modInverse(a[n - m], mod)) % mod;
  return p;
}
vector<long long int> p(long long int n) {
  long long int x = 0;
  vector<long long int> v;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  return v;
}
long long int bsearch(vector<long long int> arr, long long int l,
                      long long int r, int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return bsearch(arr, l, mid - 1, x);
    return bsearch(arr, mid + 1, r, x);
  }
  return l + (r - l) / 2;
}
long long int decToBinary(long long int n) {
  long long int f = 0;
  for (int i = 31; i >= 0; i--) {
    int k = n >> i;
    if (k & 1) f += 1;
  }
  return (f) % 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n, m, p;
    cin >> n >> m >> p;
    vector<long long int> a(n);
    for (__typeof(n) i = 0; i < n; i += 1) {
      cin >> a[i];
    };
    vector<long long int> b(m);
    for (__typeof(m) i = 0; i < m; i += 1) {
      cin >> b[i];
    };
    if ((a[0] % p) && (b[0] % p)) {
      cout << 0 << endl;
      break;
    }
    if (a[n - 1] % p && (b[m - 1] % p)) {
      cout << n + m - 2 << endl;
      break;
    }
    long long int f = -1;
    long long int s = -1;
    for (__typeof(n) i = 0; i < n; i += 1) {
      if (a[i] % p) {
        f = i;
        break;
      }
    }
    for (__typeof(m) i = 0; i < m; i += 1) {
      if (b[i] % p) {
        s = i;
        break;
      }
    }
    cout << f + s << endl;
  }
}
