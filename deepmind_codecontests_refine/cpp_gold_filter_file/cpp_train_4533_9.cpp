#include <bits/stdc++.h>
using namespace std;
int cond = (long long)1;
int n, m;
const int MAX = (int)2e6 + 11;
array<string, 30> in = {};
array<int, MAX> src = {};
array<array<int, MAX>, 31> reach = {};
void solve() {
  cin >> n >> m;
  {
    if (cond > 0) {
      cond--;
      for (auto xxx = (0); xxx < (1); ++xxx)
        cerr << 31 << " "
             << "n << \" \" << m"
             << " " << n << " " << m << endl;
      cerr.flush();
    }
  };
  for (auto i = (0); i < (n); ++i) cin >> in[i];
  for (auto i = (0); i < (n); ++i) {
    int bit = 1 << i;
    for (auto j = (0); j < (m); ++j) src[j] |= bit * (in[i][j] - '0');
  }
  for (auto j = (0); j < (m); ++j) {
    {
      if (cond > 0) {
        cond--;
        for (auto xxx = (0); xxx < (1); ++xxx)
          cerr << 38 << " "
               << "j << \" \" << src[j]"
               << " " << j << " " << src[j] << endl;
        cerr.flush();
      }
    };
    reach[0][src[j]]++;
    reach[0][((1 << n) - 1) ^ src[j]]++;
  }
  for (auto i = (0); i < (n); ++i) {
    int bit = 1 << i;
    for (auto j = (n); j >= (1); --j) {
      for (auto oldMask = (0); oldMask < ((1 << n)); ++oldMask) {
        int newMask = oldMask ^ bit;
        reach[j][newMask] += reach[j - 1][oldMask];
      }
    }
  }
  long long res = (int)1e9;
  int half = n / 2;
  for (auto mm = (0); mm < ((1 << n)); ++mm) {
    long long sol = 0;
    for (auto steps = (0); steps <= (half); ++steps) {
      long long cur = steps * reach[steps][mm];
      if (steps * 2 == n)
        sol += cur / 2;
      else
        sol += cur;
    }
    res = min(res, sol);
  }
  cout << res << endl;
}
const int multi = 0;
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
  int t;
  if (multi)
    cin >> t;
  else
    t = 1;
  for (auto i = (1); i <= (t); ++i) {
    if (cond) cerr << 76 << " " << i << endl;
    if (multi) {
      printf("Case #%d:", i);
    }
    solve();
    fflush(stdout);
    cerr.flush();
  }
  return 0;
}
