#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool cmp(pair<string, int> &a, pair<string, int> &b) {
  return a.second < b.second;
}
void sort(map<string, int> &M) {
  vector<pair<string, int> > A;
  for (auto &it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
  for (auto &it : A) {
    cout << it.first << ' ' << it.second << endl;
  }
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int fact(long long int n, long long int p) {
  return (n == 1 || n == 0) ? 1 : (n * (fact(n - 1, p)));
}
long long int nof(long long int n) {
  if (n == 1) {
    return 1;
  }
  long long int ans = 2;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n) {
        ans += 1;
      } else {
        ans += 2;
      }
    }
  }
  return ans;
}
long long int power(long long int num, long long int deg, long long int m) {
  if (!deg) return 1;
  if (deg % 2) {
    return (power(num, deg - 1, m) * num) % m;
  } else {
    long long int sqrt_res = power(num, deg / 2, m);
    return (sqrt_res * sqrt_res) % m;
  }
}
void seive(vector<long long int> &prm) {
  bool mark[102] = {false};
  long long int size = 102;
  mark[0] = true;
  mark[1] = true;
  for (long long int i = 2; i * i < size; i++) {
    if (mark[i] == false) {
      for (long long int j = i + i; j < size; j += i) {
        mark[j] = true;
      }
    }
  }
  for (long long int i = 0; i < 102; i++) {
    if (mark[i] == false) {
      prm.push_back(i);
    }
  }
}
bool stt(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first > b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n, p;
    cin >> n >> p;
    vector<double> not_prb(n);
    double count = 0;
    for (long long int i = 0; i < n; i++) {
      long long int a, b;
      cin >> a >> b;
      not_prb[i] = (1 - (double)((b / p - (a - 1) / p)) / (b - a + 1));
    }
    for (long long int i = 0; i < n; i++) {
      count += (1 - not_prb[i] * not_prb[(i + 1) % (n)]);
    }
    cout << setprecision(6) << (count * 2000);
  }
  return 0;
}
