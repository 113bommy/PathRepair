#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int maxn = 1e9, minn = -1e9;
long long modpow(long long base, long long exp, int modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int sqr(int x) { return x * x; }
bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
string w;
void func(string x) {
  int n = x.size();
  string str1 = "oo", str2 = "h";
  string y;
  y.clear();
  int a = 0;
  for (int j = 0; j < n; ++j) {
    if (j + 1 < n && x[j] == 'k' && x[j + 1] == 'h') {
      y.insert(a, str2);
      ++a;
      ++j;
    } else if (x[j] == 'u') {
      y.insert(a, str1);
      a += 2;
    } else {
      char z = x[j];
      stringstream s;
      string c;
      c.clear();
      s << z;
      s >> c;
      y.insert(a, c);
      ++a;
    }
  }
  n = y.size();
  int k = 0;
  for (int j = 0; j < n; ++j) {
    if (j + 1 < n && y[j] == 'k' && y[j + 1] == 'h') {
      k = 1;
    }
    if (y[j] == 'u') {
      k = 1;
    }
  }
  if (k == 1)
    func(y);
  else
    w = y;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<string> lol;
  lol.clear();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    w.clear();
    func(x);
    if (lol.find(w) == lol.end()) {
      lol.insert(w);
      ans++;
    }
  }
  cout << ans;
  return 0;
}
