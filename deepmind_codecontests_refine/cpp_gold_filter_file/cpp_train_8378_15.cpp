#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > f;
int main() {
  int h, q;
  scanf("%d %d\n", &h, &q);
  long long l = 1LL << (h - 1);
  long long r = (1LL << h) - 1;
  f.emplace_back(make_pair(r + 1, r + 1));
  for (int i = 0; i < q; i++) {
    long long v, x, y, ans;
    scanf("%lld %lld %lld %lld\n", &v, &x, &y, &ans);
    x <<= h - v;
    ((y += 1) <<= h - v)--;
    if (ans == 1) {
      l = max(l, x);
      r = min(r, y);
    } else {
      f.emplace_back(x, y);
    }
  }
  sort(f.begin(), f.end());
  long long ans = -1;
  for (auto it : f) {
    long long x, y;
    tie(x, y) = it;
    if (l < x && l <= r) {
      if (ans != -1 || (l + 1 < x && l + 1 <= r)) {
        cout << "Data not sufficient!" << endl;
        return 0;
      }
      ans = l;
    }
    l = max(l, y + 1);
  }
  if (ans == -1) {
    cout << "Game cheated!" << endl;
    return 0;
  }
  cout << ans << endl;
  fprintf(stderr, "Execution time = %.4lfsec",
          (double)clock() / (double)CLOCKS_PER_SEC);
  return 0;
}
