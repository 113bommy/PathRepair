#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<long long> fact(21, 1);
  for (int i = 2; i < 21; i++) fact[i] = fact[i - 1] * i;
  ;
  while (t--) {
    long long k;
    cin >> k;
    vector<long long> a;
    for (long long i = 2; k > 0; i++) {
      a.push_back(k % i);
      k /= i;
    }
    sort((a).begin(), (a).end());
    ;
    vector<long long> count(50, 0);
    for (long long x : a) count[x]++;
    long long out = 0, r, seen;
    for (long long e = a.size() + 3; e > 0; e--) {
      if (count[e] == 0) continue;
      r = 1;
      seen = 0;
      count[e]--;
      ;
      for (long long x = a.size() + 3; x >= 0; x--) {
        if (count[x] == 0) continue;
        r *= fact[a.size() - max(1ll, x) - seen] / fact[count[x]] /
             fact[a.size() - max(1ll, x) - seen - count[x]];
        ;
        seen += count[x];
      }
      count[e]++;
      out += r;
    }
    cout << out - 1 << " ";
  }
}
