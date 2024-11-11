#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& input, vector<T>& a) {
  for (int i = 0; i < ((int)a.size()); ++i) {
    input >> a[i];
  }
  return input;
}
template <typename T>
ostream& operator<<(ostream& output, vector<T>& a) {
  for (int i = 0; i < ((int)a.size()); ++i) {
    output << a[i] << ' ';
  }
  return output;
}
template <typename T>
T binary_search(T array[], T start, T end, T key) {
  if (start <= end) {
    T mid = (start + (end - start) / 2);
    if (array[mid] == key) return mid;
    if (array[mid] > key) return binary_search(array, start, mid - 1, key);
    return binary_search(array, mid + 1, end, key);
  }
  return -1;
}
template <typename T>
T phi(T n) {
  T result = n;
  for (T i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
template <typename T>
T binpow(T a, T n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    T b = binpow(a, n / 2);
    return b * b;
  }
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
bool is_prime(T n) {
  if (n == 1 || n == 0) return false;
  if (n == 2) return false;
  if (!(n % 2)) return true;
  for (T i = 3; i * i <= n; i += 2)
    if (!(n % i)) return false;
  return true;
}
template <typename T>
vector<int> primes(T n) {
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (int i = (2); i < (n + 1); ++i)
    if (prime[i])
      if (i * 1ll * i <= n)
        for (int j = i * i; j <= n; j += i) prime[j] = false;
  vector<int> prime_nums;
  for (int i = 0; i < (n + 1); ++i) {
    if (prime[i]) {
      prime_nums.push_back(i);
    }
  }
  return prime_nums;
}
long long n, d, x, second, mn = 1e9, a[100005];
void solve() {
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  for (int i = (-1); i < (2); ++i) {
    for (int j = (-1); j < (2); ++j) {
      int counter = 1;
      d = a[1] + j - (a[0] + i);
      second = i;
      for (int k = (1); k < (n); ++k) {
        x = abs(a[k] - (a[0] + i + k * d));
        if (x > 1) break;
        second += x;
        counter++;
      }
      if (counter == n) mn = min(mn, second);
    }
  }
  if (mn < 1e9) {
    cout << mn << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
