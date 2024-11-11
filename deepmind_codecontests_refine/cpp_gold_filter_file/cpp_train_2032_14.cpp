#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a1, a2, b1, b2;
long long ans;
void update(long long diff, int i1, int i2, int j1, int j2) {
  if (ans > diff) {
    ans = diff;
    a1 = i1, a2 = i2, b1 = j1, b2 = j2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto& i : a) cin >> i;
  int m;
  cin >> m;
  vector<long long> b(m);
  for (auto& i : b) cin >> i;
  long long sa = 0, sb = 0;
  for (auto i : a) sa += i;
  for (auto i : b) sb += i;
  a1 = a2 = b1 = b2 = -1;
  ans = abs(sa - sb);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long diff = abs(sa - sb + 2 * (b[j] - a[i]));
      update(diff, i + 1, -1, j + 1, -1);
    }
  }
  vector<pair<long long, pair<int, int>>> sumB;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      sumB.push_back(make_pair(b[i] + b[j], make_pair(i + 1, j + 1)));
    }
  }
  sort(sumB.begin(), sumB.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long sumA = a[i] + a[j];
      auto it = lower_bound(sumB.begin(), sumB.end(),
                            make_pair((sb - sa) / 2 + sumA, make_pair(0, 0)));
      if (it != sumB.end()) {
        long long sumB0 = it->first;
        int x, y;
        tie(x, y) = it->second;
        long long diff = abs(sa - sb + 2 * (sumB0 - sumA));
        update(diff, i + 1, j + 1, x, y);
      }
      if (it != sumB.begin()) --it;
      if (it != sumB.end()) {
        long long sumB0 = it->first;
        int x, y;
        tie(x, y) = it->second;
        long long diff = abs(sa - sb + 2 * (sumB0 - sumA));
        update(diff, i + 1, j + 1, x, y);
      }
    }
  }
  cout << ans << '\n';
  if (a1 < 0)
    cout << 0 << '\n';
  else if (a2 < 0)
    cout << 1 << '\n' << a1 << " " << b1 << '\n';
  else
    cout << 2 << '\n' << a1 << " " << b1 << '\n' << a2 << " " << b2 << '\n';
  return 0;
}
