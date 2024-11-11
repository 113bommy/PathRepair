#include <bits/stdc++.h>
using namespace std;
double Fib(double x, double z);
string BinDec(unsigned long long x);
string StringInt(long long x);
unsigned long long StringInt(string x);
unsigned long long BinDec(string x);
unsigned long long POWMOD(unsigned long long x, unsigned long long y,
                          unsigned long long mod);
unsigned long long POWE(long long, long long);
vector<pair<string, int> > z;
vector<vector<string> > ans(1000000);
int lol(int i, int s, int l) {
  int jl = i;
  ans[l].push_back(z[i].first);
  if (s == 0) return i;
  for (int k = 0; k < s; k++) {
    jl = lol(jl + 1, z[jl + 1].second, l + 1);
  }
  return jl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string x;
  cin >> x;
  int j = 0;
  while (1) {
    if (j >= x.size()) break;
    string a, b;
    int s;
    while (1) {
      if (x[j] == ',' || j >= x.size()) break;
      a += x[j];
      j++;
    }
    j++;
    while (1) {
      if (x[j] == ',' || j >= x.size()) break;
      b += x[j];
      j++;
    }
    j++;
    s = StringInt(b);
    z.push_back({a, s});
  }
  int i = -1;
  while (1) {
    if (i + 1 >= z.size()) break;
    i = lol(i + 1, z[i + 1].second, 0);
  }
  int s = 0;
  for (i = 0; i < 1000000; i++) {
    if (ans[i].empty()) break;
    s++;
  }
  cout << s << endl;
  for (i = 0; i < s; i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
double Fib(double x, double z) {
  int i = 0;
  double f = x, r = x, t;
  for (i = 2; i < z; i++) {
    t = f;
    f += r;
    r = t;
  }
  return f;
}
string BinDec(unsigned long long x) {
  string z;
  while (1) {
    z += ((x % 3) + '0');
    x /= 3;
    if (x == 0) break;
  }
  while (1) {
    if (z.size() == 30) break;
    z += '0';
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long BinDec(string x) {
  long long i;
  unsigned long long z = 1, a = 0;
  for (i = x.size() - 1; i >= 0; i--) {
    if (x[i] == '1') a += z;
    if (x[i] == '2') a += (2 * z);
    z *= 3;
  }
  return a;
}
unsigned long long StringInt(string x) {
  unsigned long long z = 0, i;
  for (i = 0; i < x.size(); i++) {
    z *= 10;
    z += (x[i] - '0');
  }
  return z;
}
string StringInt(long long x) {
  string z;
  while (x != 0) {
    z += (x % 10 + '0');
    x /= 10;
  }
  reverse(z.begin(), z.end());
  return z;
}
unsigned long long POWMOD(unsigned long long base, unsigned long long exp,
                          unsigned long long mod) {
  unsigned long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    res %= mod;
    exp /= 2;
    base = (base * base);
    base %= mod;
  }
  return res % mod;
}
unsigned long long POWE(long long base, long long exp) {
  unsigned long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    exp /= 2;
    base = (base * base);
  }
  return res;
}
