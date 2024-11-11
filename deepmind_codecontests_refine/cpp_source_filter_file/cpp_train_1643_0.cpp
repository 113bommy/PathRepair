#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int pcnt(int x) { return __builtin_popcount(x); }

int f(int x) {
  if (x == 0) return 0;
  return f(x % pcnt(x)) + 1;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> x(n);
  rep(i, n) x[i] = s[i] - '0';
  int pc = 0;
  rep(i, n) pc += x[i];
  vector<int> ans(n, 0);
  rep(b, 2) {
    int npc = pc;
    if (b == 0)
      npc++;
    else
      npc--;
    if (pcnt <= 0) continue;
    int r0 = 0;
    rep(i, n) {
      r0 = (r0 * 2) % npc;
      r0 += x[i];
    }
    int k = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (x[i] == b) {
        int r = r0;
        if (b == 0)
          r = (r + k) % npc;
        else
          r = (r - k + npc) % npc;
        ans[i] = f(r) + 1;
      }
      k = (k * 2) % npc;
    }
  }

  rep(i, n) cout << ans[i] << endl;

  return 0;
}