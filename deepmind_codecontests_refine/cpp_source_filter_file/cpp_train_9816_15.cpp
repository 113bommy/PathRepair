#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
const long long INF = 1e18;
const int MOD = 1e9 + 7;
long long fac[15];
long long pf[20];
vector<int> fin;
long long n, q;
void des(long long x) {
  int i = 14;
  while (i > 0) {
    pf[i] = x / fac[i];
    x %= fac[i--];
  }
  vector<int> pos;
  long long a = max(1LL, n - 14);
  for (int i = a; i < n + 1; i++) pos.push_back(i);
  fin.clear();
  for (int i = pos.size() - 1; i >= 0; i--) {
    fin.push_back(pos[pf[i]]);
    pos.erase(pos.begin() + pf[i]);
  }
}
long long sum(int x) {
  long long r = 0;
  for (int i = 0; i < x; i++) r += fin[i];
  return r;
}
void go() {
  cin >> n >> q;
  fac[0] = 1;
  for (long long i = 1; i < 15; i++) fac[i] = fac[i - 1] * i;
  des(0);
  long long cont = 0;
  while (q--) {
    int c;
    cin >> c;
    if (c == 2) {
      long long x;
      cin >> x;
      cont += x;
      des(cont);
      continue;
    }
    int l, r;
    cin >> l >> r;
    if (n <= 15) {
      long long a = sum(l - 1);
      long long b = sum(r);
      cout << b - a << "\n";
    } else {
      long long m = n - 15;
      if (l > m) {
        long long a = sum(l - 1 - m);
        long long b = sum(r - m);
        cout << b - a << "\n";
      } else if (r < m + 1) {
        cout << ((r - l + 1) * (r + l)) / 2 << "\n";
      } else {
        long long a = sum(r - m);
        long long b = ((m + l) * (m - l - 1)) / 2;
        cout << a + b << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) go();
  return 0;
}
