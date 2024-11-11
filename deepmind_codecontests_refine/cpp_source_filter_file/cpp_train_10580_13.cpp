#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long expo, long long MOD) {
  long long res = 1 % MOD;
  while (expo > 0) {
    if (expo & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    expo >>= 1;
  }
  return res;
}
long long seed;
long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
int main() {
  {
    int n, m;
    long long vmax;
    scanf("%d", &n), scanf("%d", &m), scanf("%lld", &seed),
        scanf("%lld", &vmax);
    long long arr;
    map<int, long long> mp;
    for (int i = 0; i < n; ++i) {
      arr = (rnd() % vmax) + 1;
      mp.insert(mp.end(), {i + 1, arr});
    }
    mp.insert(mp.end(), {n + 1, 0LL});
    for (int j = 0; j < m; ++j) {
      int op, l, r;
      op = (rnd() % 4) + 1;
      l = (rnd() % n) + 1;
      r = (rnd() % n) + 1;
      if (l > r) swap(l, r);
      long long x, y;
      auto leftIterator = mp.lower_bound(l);
      if (leftIterator->first != l)
        --leftIterator, mp[l] = (leftIterator)->second,
                        leftIterator = mp.lower_bound(l);
      auto iteratorNextToRight = mp.lower_bound(r);
      if (iteratorNextToRight->first != r + 1)
        --iteratorNextToRight,
            mp[r + 1] = iteratorNextToRight->second,
                   iteratorNextToRight = mp.lower_bound(r + 1);
      switch (op) {
        case 1: {
          x = (rnd() % vmax) + 1;
          while (leftIterator != iteratorNextToRight) {
            leftIterator->second += x;
            leftIterator++;
          }
          break;
        }
        case 2: {
          x = (rnd() % vmax) + 1;
          mp.erase(leftIterator, iteratorNextToRight);
          mp[l] = x;
          break;
        }
        case 3: {
          x = (rnd() % (r - l + 1)) + 1;
          vector<pair<long long, long long>> sol;
          for (; leftIterator != iteratorNextToRight;) {
            long long val = leftIterator->second;
            int l = leftIterator->first;
            ++leftIterator;
            int cnt = min((leftIterator)->first, r + 1) - l;
            sol.push_back({val, cnt});
          }
          sort(sol.begin(), sol.end());
          int cnt = 0;
          for (int i = 0; i < sol.size(); ++i) {
            cnt += sol[i].second;
            if (cnt >= x) {
              printf("%lld\n", sol[i]);
              break;
            }
          }
          break;
        }
        case 4: {
          x = (rnd() % vmax) + 1;
          y = (rnd() % vmax) + 1;
          long long ans = 0;
          for (; leftIterator != iteratorNextToRight;) {
            long long val = leftIterator->second;
            int l = leftIterator->first;
            ++leftIterator;
            int cnt = min((leftIterator)->first, r + 1) - l;
            ans = (ans + (power(val % y, x, y) * cnt) % y) % y;
          }
          printf("%lld\n", ans);
          break;
        }
      }
    }
  }
  return 0;
}
