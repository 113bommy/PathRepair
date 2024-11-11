#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
vector<long long> forbid;
long long xpow(long long a, long long n) {
  if (n == 0) return 1;
  long long r = xpow(a, n / 2);
  r *= r;
  if (n & 1) r *= a;
  return r;
}
map<pair<int, int>, int> f;
long long n;
int go(int a, int b) {
  if (f.count(make_pair(a, b))) return f[make_pair(a, b)];
  int &res = f[make_pair(a, b)];
  if (b == 1) {
    if (forbid[b + 1] <= a) {
      if ((n - a) % 2 == 0)
        return res = -1;
      else
        return res = 1;
    }
  }
  if (a == 1 && forbid[b] == 2) return 0;
  if (forbid[b] < a) return -1;
  int r1 = 1;
  if (forbid[b] > a + 1) r1 = go(a + 1, b);
  int r2 = 1;
  if (forbid[b + 1] > a) r2 = go(a, b + 1);
  if (r1 == -1 || r2 == -1) return res = 1;
  if (r1 == 0 || r2 == 0) return res = 0;
  return res = -1;
}
int main() {
  long long a, b;
  cin >> a >> b >> n;
  forbid.resize(40);
  forbid[1] = n;
  for (int i = 2; i < forbid.size(); ++i) {
    long long r = 1;
    long long v = xpow(r, i);
    while (v < n) {
      r++;
      v = xpow(r, i);
    }
    forbid[i] = r;
  }
  int x = go(a, b);
  if (x == -1)
    cout << "Stas" << endl;
  else if (x == 1)
    cout << "Masha" << endl;
  else
    cout << "Missing" << endl;
  return 0;
}
