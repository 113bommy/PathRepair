#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int modFact(long long int n, long long int p) {
  long long int result = 1;
  for (long long int i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
int fact(int n);
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}
void solve(long long int n, long long int a, long long int b, long long int c,
           long long int* arr) {
  long long int x = -100000;
  ;
  long long int y = -100000;
  ;
  long long int z = -100000;
  ;
  if (n > a) {
    if (arr[n - a] == -1) solve(n - a, a, b, c, arr);
    x = arr[n - a];
  }
  if (n > b) {
    if (arr[n - b] == -1) solve(n - b, a, b, c, arr);
    y = arr[n - b];
  }
  if (n > c) {
    if (arr[n - c] == -1) solve(n - c, a, b, c, arr);
    z = arr[n - c];
  }
  if (n == a) x = 0;
  if (n == b) y = 0;
  if (n == c) z = 0;
  arr[n] = max(max(x, y), z) + 1;
}
long long Divisors(long long n, long long y) {
  long long s = 0;
  long long i = n / (y + 1);
  i = max(i, (long long)1);
  for (; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i <= y + 1 && i < n / i - 1) s++;
    }
  }
  return s;
}
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return a.second < b.second;
}
void sort(map<long long, long long>& M) {
  vector<pair<long long, long long> > A;
  for (auto& it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
}
char notc(char* a) {
  if (*a == '1')
    return '0';
  else
    return '1';
}
string change(string a, long long c, long long n) {
  for (long long i = c; i >= 0; i--) {
    a[i] = notc(&(a[i]));
  }
  char b[n];
  for (long long i = c; i >= 0; i--) {
    b[i] = a[c - i];
  }
  for (long long i = c + 1; i < n; i++) {
    b[i] = a[i];
  }
  return b;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<long long> v;
    long long p = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] != b[i]) {
        if ((notc(&(a[0]))) == b[i]) {
          v.push_back(i + 1);
          p++;
          a = change(a, i, n);
        } else {
          v.push_back(1);
          v.push_back(i + 1);
          p += 2;
          a = change(a, 0, n);
          a = change(a, i, n);
        }
      }
    }
    cout << p << " ";
    for (auto i = v.begin(); i != v.end(); i++) {
      cout << *i << " ";
    }
    cout << "\n";
  }
}
