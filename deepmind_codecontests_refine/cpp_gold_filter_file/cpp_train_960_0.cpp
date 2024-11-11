#include <bits/stdc++.h>
using namespace std;
int T;
long long a, b, q, l, r;
int main() {
  cin >> T;
  while (T--) {
    cin >> a >> b >> q;
    bool tab[a * b];
    long long sum = 0LL;
    long long sus[a * b + 1];
    sus[0] = 0;
    for (int i = 0; i < a * b; i++) {
      tab[i] = ((i % b) % a != (i % a) % b);
      if (tab[i]) sus[i]++;
      sus[i + 1] = sus[i];
      if (tab[i]) sum++;
    }
    long long res;
    while (q--) {
      res = 0;
      cin >> l >> r;
      if (l % (a * b) > 0) res -= sus[l % (a * b) - 1];
      l -= l % (a * b);
      res += sus[r % (a * b)];
      r -= r % (a * b);
      res += sum * ((r - l) / (a * b));
      cout << res << " \n"[q == 0];
    }
  }
  return 0;
}
