#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[200050];
long long f[200050];
long long q[200050];
int t[200050], fr, bk = -1;
int t2[200050], fr2, bk2;
int main() {
  cin >> n >> k >> (s + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + i;
    while (fr <= bk && t[fr] <= i) ++fr;
    if (t2[fr2] < i - k - 1) ++fr2;
    if (s[i] == '1') {
      long long h = i + f[t2[fr2]];
      while (fr <= bk && q[bk] >= h) --bk;
      ++bk;
      q[bk] = h;
      t[bk] = i + k + 1;
    }
    if (fr <= bk) f[i] = min(f[i], q[fr]);
    while (fr2 <= bk2 && f[t2[bk2]] >= f[i]) --bk2;
    ++bk2;
    t2[bk2] = i;
  }
  cout << f[n] << '\n';
  return 0;
}
