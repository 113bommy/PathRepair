#include <bits/stdc++.h>
using namespace std;
string itos(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int xorsum, n, a[110];
map<int, int> grun;
int sieve[31700];
vector<int> p;
int mex(set<int> &s) {
  for (int i = 0;; i++)
    if (not s.count(i)) return i;
}
int getGrundy(int x) {
  if (grun.count(x)) return x;
  if (x == 1) return grun[x] = 0;
  set<int> s;
  for (int i = 1; (1 << i) <= x; i++)
    s.insert(getGrundy(x >> i | (x & ((1 << i) - 1))));
  return grun[x] = mex(s);
}
void solve(int x) {
  int mask = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (a[i] % x == 0) cnt++, a[i] /= x;
    mask |= (1 << cnt);
  }
  xorsum ^= getGrundy(mask);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < 31700; i++) {
    if (not sieve[i]) {
      p.push_back((i));
      for (int j = i * i; j < 31700; j += i) sieve[j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    auto it1 = p.begin();
    while (a[i] > 1) {
      if (it1 == p.end()) {
        solve(a[i]);
        break;
      } else if (a[i] % *it1 == 0)
        solve(*it1);
      it1++;
    }
  }
  cout << (xorsum ? "Mojtaba" : "Arpa") << endl;
  return 0;
}
