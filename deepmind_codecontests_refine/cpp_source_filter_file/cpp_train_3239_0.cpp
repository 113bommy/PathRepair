#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(array<T, 2> &arr);
template <typename T>
void print(vector<T> &v);
template <typename T>
void print(deque<T> &v);
template <typename T>
T _gcd(T a, T b);
template <typename T>
vector<T> sieve(T n);
template <typename T>
T power(T x, T y, long long p = LLONG_MAX);
long long nxt();
template <typename T>
T modInverse(T n, T p);
long long gcd(vector<long long> &diff) {
  long long g = 0;
  long long n = diff.size();
  for (int i = 0; i < n; i++) {
    g = _gcd(g, diff[i]);
  }
  return g;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) {
    long long n = nxt(), m = nxt();
    long long mini = max(0ll, n - 2 * m);
    cout << mini << " ";
    for (int j = 0; j < n; j++) {
      if ((j * j - j) / 2 >= m) {
        cout << n - j << endl;
        break;
      }
    }
  }
}
template <typename T>
T power(T x, T y, long long p) {
  T res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
template <typename T>
vector<T> sieve(T n) {
  vector<bool> prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = 2; j * i <= n; j++) {
        prime[i * j] = false;
      }
    }
  }
  vector<T> ans;
  for (int i = 2; i <= n; i++) {
    if (prime[i]) ans.push_back(i);
  }
  return ans;
}
template <typename T>
T _gcd(T a, T b) {
  T temp1 = max(a, b), temp2 = min(a, b);
  a = temp1, b = temp2;
  if (a == 0) return b;
  if (b == 0) return a;
  if (a % b == 0) return b;
  return _gcd(b, a % b);
}
template <typename T>
void print(array<T, 2> &arr) {
  cout << arr[0] << " " << arr[1] << endl;
}
template <typename T>
void print(vector<T> &v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
T modInverse(T n, T p) {
  return power(n, p - 2, p) % p;
}
template <typename T>
void print(deque<T> &v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
long long nxt() {
  long long x;
  cin >> x;
  return x;
}
