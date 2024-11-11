#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> all[1000005];
long long now = 1;
vector<long long> have;
int main() {
  long long N, M, i, j, ans = 0, l = 0, r, t, a, b;
  scanf("%lld %lld", &N, &M);
  l = 0;
  r = M + 1;
  if (M == 1)
    printf("%d\n", 1);
  else {
    for (i = 1; i <= M + 1; i++) all[i] = make_pair(-1, -1);
    for (i = 0; i < N; i++) {
      scanf("%lld", &t);
      if (all[t].first == -1)
        all[t] = make_pair(i, i);
      else
        all[t].second = i;
    }
    for (i = 1; i <= M; i++)
      if (all[i].first != -1) have.push_back(i);
    N = have.size();
    for (i = 0; i < N; i++) all[i] = all[have[i]];
    for (i = 1; i < N; i++)
      if (all[i].first <= all[i - 1].second) break;
    l = i - 1;
    for (i = N - 2; i >= 0; i--)
      if (all[i].second >= all[i + 1].first) break;
    r = i + 1;
    if (l >= r)
      printf("%lld\n", M * (M - 1) / 2 + M);
    else {
      ans = 0;
      for (i = 1; i <= M; i++) {
        if (lower_bound(have.begin(), have.end(), i) == have.begin()) {
          a = i;
          b = M;
          while ((b - a) > 1) {
            auto y = upper_bound(have.begin(), have.end(), (a + b) / 2);
            if (y == have.end() || (*y) >= have[r])
              b = (a + b) / 2;
            else
              a = (a + b) / 2;
          }
          auto y = upper_bound(have.begin(), have.end(), a);
          if (y == have.end() || (*y) >= have[r])
            ans += (M - a + 1);
          else
            ans += (M - b + 1);
        } else {
          auto x = lower_bound(have.begin(), have.end(), i);
          x--;
          if (*x > have[l]) break;
          a = i;
          b = M;
          while ((b - a) > 1) {
            auto y = upper_bound(have.begin(), have.end(), (a + b) / 2);
            if (y == have.end() ||
                all[x - have.begin()].second < all[y - have.begin()].first &&
                    (*y) >= have[r])
              b = (a + b) / 2;
            else
              a = (a + b) / 2;
          }
          auto y = upper_bound(have.begin(), have.end(), a);
          if (y == have.end() ||
              all[x - have.begin()].second < all[y - have.begin()].first &&
                  (*y) >= have[r])
            ans += (M - a + 1);
          else
            ans += (M - b + 1);
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
