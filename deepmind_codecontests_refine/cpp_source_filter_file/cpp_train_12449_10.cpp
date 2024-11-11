#include <bits/stdc++.h>
using namespace std;
int lol[(1 << 16)][17];
void pre() {
  memset(lol, 0, sizeof(lol));
  for (int mask = 0; mask < (1 << 16); mask++) {
    int tmp = mask;
    int mx = 0;
    while (tmp) {
      mx = max(mx, tmp % 16);
      tmp /= 16;
    }
    for (int i = 0; i < 16; i++) {
      int nmask = mask ^ (1 << max(i, mx));
      if (nmask < mask) lol[mask][i] = 1;
    }
    int nmask = mask ^ (1 << mx);
    if (nmask < mask) lol[mask][16] = 1;
    if (mask) {
      for (int i = 0; i <= 16; i++) {
        lol[mask][i] += lol[mask - 1][i];
      }
    }
  }
}
long long mem[17][2][17];
long long compute(vector<int> &dig, int ind, bool tight, int mx) {
  if (ind == 3) {
    if (tight) {
      int num = 0;
      for (int i = 3; i >= 0; i--) {
        num = num * 16 + dig[i];
      }
      return lol[num][mx];
    } else {
      return lol[(1 << 16) - 1][mx];
    }
  }
  if (mem[ind][tight][mx] != -1) return mem[ind][tight][mx];
  long long ret = 0;
  if (tight) {
    for (int i = 0; i < dig[ind]; i++) {
      int nmx = (mx == 16) ? i : max(mx, i);
      ret += compute(dig, ind - 1, false, nmx);
    }
    int nmx = (mx == 16) ? dig[ind] : max(mx, dig[ind]);
    ret += compute(dig, ind - 1, true, mx);
  } else {
    for (int i = 0; i < 16; i++) {
      int nmx = (mx == 16) ? i : max(mx, i);
      ret += compute(dig, ind - 1, false, nmx);
    }
  }
  return mem[ind][tight][mx] = ret;
}
long long getNum(string str) {
  long long ret = 0;
  for (auto ch : str) {
    if ('0' <= ch && ch <= '9')
      ret = ret * 16 + ch - '0';
    else
      ret = ret * 16 + ch - 'a' + 10;
  }
  return ret;
}
long long compute(long long n) {
  if (n < (1 << 16)) return lol[n][16];
  vector<int> dig;
  while (n) {
    dig.push_back(n % 16);
    n /= 16;
  }
  memset(mem, -1, sizeof(mem));
  return compute(dig, int(dig.size()) - 1, true, 16);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  pre();
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    string s;
    cin >> s;
    l = getNum(s);
    cin >> s;
    r = getNum(s);
    long long ans = compute(r);
    if (l > 1) ans -= compute(l - 1);
    cout << ans << '\n';
  }
  return 0;
}
