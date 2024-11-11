#include <bits/stdc++.h>
using namespace std;
struct Linear {
  long long a;
  long long b;
  long long c;
  long long d;
};
long long LG = 61;
long long k, p;
Linear un(Linear f, Linear s) {
  Linear ans;
  ans.a = (f.a * s.a + f.c * s.b) % p;
  ans.b = (s.a * f.b + f.d * s.b) % p;
  ans.c = (f.a * s.c + f.c * s.d) % p;
  ans.d = (s.c * f.b + f.d * s.d) % p;
  return ans;
}
int32_t main() {
  cin >> k >> p;
  long long n, m, J, v;
  cin >> n;
  vector<long long> s(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<pair<long long, long long> > ch;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> J >> v;
    if (J < k) {
      ch.push_back(make_pair(J, v));
    }
  }
  m = ch.size();
  sort(ch.begin(), ch.end());
  Linear binup[n][LG];
  for (long long i = 0; i < n; i++) {
    long long a = s[(i + 1) % n];
    long long b = s[i];
    Linear l = {a, b, 1, 0};
    binup[i][0] = l;
  }
  Linear l1, l2;
  for (long long i = 1; i < LG; i++) {
    for (long long j = 0; j < n; j++) {
      long long sdv = j + (1LL << (i - 1));
      long long ind = sdv % n;
      l1 = binup[j][i - 1];
      l2 = binup[ind][i - 1];
      Linear l3 = un(l1, l2);
      binup[j][i] = l3;
    }
  }
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long FF = 1;
  long long SS = 0;
  long long u = 0;
  k--;
  long long START = 0;
  while (u < m) {
    long long next = ch[u].first;
    long long free = max((long long)0, next - START - 1);
    for (long long i = LG - 1; i >= 0; i--) {
      if (free < (1LL << i)) continue;
      free -= (1LL << i);
      k -= (1LL << i);
      Linear LL = binup[START % n][i];
      long long NF = (FF * LL.a + SS * LL.b) % p;
      long long NS = (FF * LL.c + SS * LL.d) % p;
      FF = NF, SS = NS;
      START += (1LL << i);
    }
    long long old = next - 1;
    long long old_v;
    if (next > 0) {
      old_v = s[(next - 1) % n];
    }
    while (u < m && ch[u].first - 1 == old) {
      if (ch[u].first != 0) {
        long long NF = (ch[u].second * FF + old_v * SS) % p;
        SS = FF;
        FF = NF;
        k--;
        START++;
      }
      old_v = ch[u].second;
      old = ch[u].first;
      u++;
    }
    START++;
    if (k != 0) {
      long long NF = (s[START % n] * FF + old_v * SS) % p;
      SS = FF;
      FF = NF;
      k--;
    }
  }
  for (long long i = LG - 1; i >= 0; i--) {
    if (k < (1LL << i)) continue;
    k -= (1LL << i);
    Linear LL = binup[START % n][i];
    long long NF = (FF * LL.a + SS * LL.b) % p;
    long long NS = (FF * LL.c + SS * LL.d) % p;
    FF = NF, SS = NS;
    START += (1LL << i);
  }
  cout << FF % p << endl;
  return 0;
}
