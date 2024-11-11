#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, q;
long long int m;
vector<long long int> mods;
long long int w[N];
long long int phi(long long int x) {
  long long int ans = x;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans -= ans / i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    ans -= ans / x;
  }
  return ans;
}
long long int magic(long long int x, long long int mod) {
  if (x < 32) {
    return x;
  }
  return 32 + (x - 32) % mod;
}
long long int fexp(long long int base, long long int e, long long int mod) {
  long long int ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans = magic(ans * base, mod);
    }
    base = magic(base * base, mod);
    e >>= 1;
  }
  return ans;
}
long long int go(int l, int r, int on) {
  if (r == l) {
    return magic(w[l], mods[on]);
  }
  if (mods[on] == 1) {
    return 0;
  }
  long long int e = go(l + 1, r, on + 1);
  return fexp(w[l], e, mods[on]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  mods.push_back(m);
  while (mods.back() != 1) {
    mods.push_back(phi(mods.back()));
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << go(l, r, 0) % mods[0] << endl;
  }
  return 0;
}
