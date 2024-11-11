#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC Optimization("O3")
#pragma GCC Optimization("unroll-loops")
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007;
const int mod2 = 998244353;
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
vector<int> sieve(int n);
vector<int> factorial(int n, int m);
vector<int> radixsort(vector<int> v, int base, int max);
void solve() {
  int n, a, b, c, x, y, z;
  cin >> n;
  a = b = c = 0;
  while (n--) {
    read(x, y, z);
    a += x;
    b += y;
    c += z;
  }
  if (a == 0 and b == 0 and c == 0) {
    cout << "Yes";
  } else
    cout << "No";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
vector<int> sieve(int n) {
  vector<int> v, x;
  v.clear();
  x.clear();
  for (int i = 0; i < n + 1; i++) {
    v.push_back(0);
  }
  for (int i = 2; i < sqrt(n) + 1; i++) {
    if (v[i] == 0) {
      for (int j = i * i; j <= n; j += i) {
        v[j] = 1;
      }
    }
  }
  v.erase(v.begin());
  v.erase(v.begin());
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 0) x.push_back(i + 2);
  }
  return x;
}
vector<int> factorial(int n, int m) {
  long long fact = 1;
  vector<int> v;
  v.push_back(fact);
  for (int i = 1; i < n + 1; i++) {
    fact *= i;
    fact = fact % m;
    v.push_back(fact);
  }
  return v;
}
vector<int> radixsort(vector<int> v, int base, int max) {
  vector<int> arr[2];
  arr[0] = v;
  arr[1].resize(v.size());
  int aux[base];
  int temp = int(log2(max) / log2(base));
  int t2 = 1;
  for (int k = 0; k <= temp; k++) {
    memset(aux, 0, sizeof(aux));
    for (int i : arr[k % 2]) {
      aux[((i / t2) % base)]++;
    }
    for (int i = 1; i < base; i++) {
      aux[i] += aux[i - 1];
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      aux[((arr[k % 2][i] / t2) % base)]--;
      arr[(k + 1) % 2][aux[((arr[k % 2][i] / t2) % base)]] = arr[k % 2][i];
    }
    t2 *= base;
  }
  return arr[(temp + 1) % 2];
}
