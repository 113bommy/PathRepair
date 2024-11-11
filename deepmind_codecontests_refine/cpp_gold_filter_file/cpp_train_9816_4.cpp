#include <bits/stdc++.h>
using namespace std;
long long fact[16];
deque<int> sira;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  clock_t st = clock();
  long long n;
  cin >> n;
  int q;
  cin >> q;
  int last[15];
  fact[0] = 1;
  for (int i = 1; i <= 15; i++) {
    fact[i] *= i;
  }
  for (int i = min(14LL, n - 1); i >= 0; i--) {
    last[min(n, 15LL) - i - 1] = n - i;
  }
  long long minn = min(n, 15LL);
  long long curperm = 0;
  while (q--) {
    int type;
    cin >> type;
    long long ans = 0;
    if (type == 1) {
      long long l, r;
      cin >> l >> r;
      if (l < n - 14) {
        if (r < n - 14) {
          ans = (r * (r + 1) / 2) - ((l - 1) * l / 2);
        } else {
          ans = ((n - 15) * (n - 14) / 2) - ((l - 1) * l / 2);
          for (int i = 0; i <= r - n + 14; i++) ans += last[i];
        }
      } else {
        for (int i = l - n + minn - 1; i <= r - n + minn - 1; i++)
          ans += last[i];
      }
      cout << ans << '\n';
    } else if (type == 2) {
      long long x;
      cin >> x;
      curperm += x;
      int pre = 0;
      set<int> s;
      for (int i = min(14LL, n - 1); i >= 0; i--) s.insert(n - i);
      long long tmp = curperm;
      for (int i = 1; i <= min(n, 15LL) && s.size(); i++) {
        int mod = tmp % i;
        tmp /= i;
        sira.push_front(mod);
      }
      for (int i = 0; i < min(n, 15LL); i++) {
        int cur = sira.front();
        sira.pop_front();
        auto it = s.begin();
        advance(it, cur);
        last[i] = *it;
        s.erase(it);
      }
    }
  }
  cerr << setprecision(10) << fixed;
  cerr << (double)(clock() - st) / CLOCKS_PER_SEC << '\n';
}
