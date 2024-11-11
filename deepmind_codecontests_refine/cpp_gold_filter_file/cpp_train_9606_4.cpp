#include <bits/stdc++.h>
using namespace std;
template <class c>
c gcd(c a, c b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
template <class c>
c lcm(c a, c b) {
  return a / gcd(a, b) * b;
}
template <class a>
bool prime(a n) {
  for (a i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
bool bigger(pair<int, int> picachu, pair<int, int> qicachu) {
  return (picachu.first < qicachu.first);
}
void printarr(int arr[], int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  cout << endl;
}
int chartoint(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a';
  if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
  return 52;
}
int kadane(int arr[], int n) {
  int maximum = arr[0];
  int max_so_far = 0;
  for (int i = 0; i < n; i++) {
    max_so_far += arr[i];
    if (max_so_far > maximum) maximum = max_so_far;
    if (max_so_far < 0) max_so_far = 0;
  }
  return maximum;
}
template <class a>
a powmod(a t1, a t2, a mod) {
  a res = 1;
  t1 = t1 % mod;
  if (t1 == 0) return 0;
  while (t2) {
    if (t2 & 1) res = (res * t1) % mod;
    t1 = (t1 * t2) % mod;
    t2 = t2 >> 1;
  }
  return res;
}
const int MOD = 1e9 + 7;
int64_t b(int64_t d) {
  int n = log2(d);
  return n + 1;
}
void run() {
  int64_t n;
  cin >> n;
  int64_t a[n];
  vector<int64_t> v(35);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[b(a[i])]++;
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  int64_t count = 0;
  for (int i = 1; i < 35; i++) {
    if (v[i] > 1) {
      count += (v[i] * (v[i] - 1)) / 2;
    }
  }
  cout << count << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int test;
  cin >> test;
  while (test--) {
    run();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
  ;
}
