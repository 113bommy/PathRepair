#include <bits/stdc++.h>
using namespace std;
const unsigned long long int M = 1e9 + 7;
using namespace std;
unsigned long long int fpow(unsigned long long int a,
                            unsigned long long int b) {
  a %= M;
  unsigned long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % M;
    }
    a = a * a % M;
    b >>= 1;
  }
  return res;
}
bool primes[10000000] = {false};
unsigned long long int spf[10000000];
void sieve() {
  primes[2] = true;
  spf[1] = 1;
  for (unsigned long long int i = 2; i < 10000000; i++) spf[i] = i;
  for (unsigned long long int i = 4; i < 10000000; i += 2) spf[i] = 2;
  for (unsigned long long int i = 3; i * i < 10000000; i++) {
    if (spf[i] == i) {
      primes[i] = true;
      for (unsigned long long int j = i * i; j < 10000000; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<unsigned long long int, unsigned long long int> gpf(
    unsigned long long int n) {
  map<unsigned long long int, unsigned long long int> v;
  unsigned long long int curr = spf[n];
  unsigned long long int cnt = 1;
  while (n > 1) {
    n /= spf[n];
    if (curr == spf[n]) {
      cnt++;
      continue;
    }
    v.insert({curr, cnt});
    curr = spf[n];
    cnt = 1;
  }
  return v;
}
struct finvic {
  vector<int> fin;
  int n;
  finvic(int n) {
    this->n = n;
    fin.assign(n, 0);
  }
  finvic(vector<int> a) : finvic(int(a.size())) {
    for (int u = 0; u < int(a.size()); u++) {
      add(u, a[u]);
    }
  }
  int sum(int r) {
    int res = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
      res += fin[i];
    }
    return res;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int ind, int val) {
    for (int i = ind; i < n; i = (i | (i + 1))) {
      fin[i] += val;
    }
  }
};
struct comp {
  bool operator()(const pair<int, pair<int, int> > &a,
                  const pair<int, pair<int, int> > &b) {
    if (a.first == b.first) return a.second.first > b.second.first;
    return a.first < b.first;
  }
};
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  return b ? gcd(b, a % b) : a;
}
map<unsigned long long int, unsigned long long int> prsqrt(
    unsigned long long int n) {
  unsigned long long int cnt = 0;
  map<unsigned long long int, unsigned long long int> m;
  while (n % 2 == 0) {
    cnt++;
    n = n / 2;
  }
  if (cnt != 0) {
    m.insert({2, cnt});
  }
  for (unsigned long long int i = 3; i <= sqrt(n); i += 2) {
    cnt = 0;
    while (n % i == 0) {
      cnt++;
      n = n / i;
    }
    if (cnt != 0) {
      m.insert({i, cnt});
    }
  }
  if (n > 2) {
    m.insert({n, 1});
  }
  return m;
}
unsigned long long int lpfact(unsigned long long int n,
                              unsigned long long int p) {
  unsigned long long int ans = 0;
  while (n) {
    ans += n / p;
    n /= p;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();
  unsigned long long int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
  } else {
    if (n == 3) {
      cout << 6 << endl;
      cout << 10 << endl;
      cout << 15 << endl;
    } else {
      vector<unsigned long long int> prime;
      int cnt = 0;
      for (int i = 0; i < 1000; i++) {
        if (primes[i]) {
          cnt++;
          prime.push_back(i);
        }
        if (cnt == n + 5) {
          break;
        }
      }
      cout << 30 << endl;
      for (int i = 0; i < n - 2; i++) {
        cout << 10 * prime[i + 3] << endl;
      }
      cout << 15 << endl;
    }
  }
  return 0;
}
