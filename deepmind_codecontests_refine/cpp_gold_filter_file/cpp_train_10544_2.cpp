#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int x;
  cin >> x;
  return x;
}
const long long INF = int(1e9) + 99;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = int(2e5) + 99;
vector<long long> plist;
bool prime[200005];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) plist.push_back(p);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int mergeSort(int arr[], int array_size) {
  int temp[array_size];
  return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(int arr[], int temp[], int left, int right) {
  int mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
int merge(int arr[], int temp[], int left, int mid, int right) {
  int i, j, k;
  int inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
long long binomialCoeff(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
long long modInverse(long long a, long long m) {
  long long g = gcd(a, m);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    return power(a, m - 2, m);
  }
}
vector<long long> v1(5001);
void modFact(int n, int p) {
  if (n >= p) return;
  long long result = 1;
  v1[0] = 1;
  for (int i = 1; i <= n; i++) {
    result = (result * i) % p;
    v1[i] = result;
  }
  return;
}
long long nCrModPFermat(long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (v1[n] * modInverse(v1[r], p) % p * modInverse(v1[n - r], p) % p) % p;
}
void solve() {
  long long l, x, r, c, g, n, y, m,
      x1 = 1, x2 = 0, x3 = 0, ans = 1e17 - 7, ans1 = 1e9 + 7, ans13 = 0,
      ans2 = 0, ans3 = 0, ans4 = 1, ans5 = 1e9 + 7, flag1 = -1, flag2 = -1;
  int k;
  cin >> n >> k;
  vector<int> v(n + 2, 0), a(n), b(k);
  map<int, int> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i + 1;
  }
  for (long long i = 0; i < k; i++) {
    cin >> b[i];
    b[i] = mp[b[i]];
    v[b[i]] = 1;
  }
  ans = 998244353;
  v[0] = 1;
  v[n + 1] = 1;
  for (long long i = 0; i < k; i++) {
    x1 *= (2 - v[b[i] - 1] - v[b[i] + 1]);
    x1 %= ans;
    v[b[i]] = 0;
  }
  cout << x1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  SieveOfEratosthenes(100000);
  long long t = 1, t1;
  cin >> t;
  t1 = t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
