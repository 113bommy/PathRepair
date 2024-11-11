#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
int a, b, c, d, n, m, k;
pair<int, int> mas[200002];
int fen[200002];
inline void upd(int first, int val) {
  for (; first <= n; first |= first + 1) {
    fen[first] += val;
  }
}
inline int fnd(int first) {
  int ans = 0;
  for (; first >= 0; first = (first & (first + 1)) - 1) {
    ans += fen[first];
  }
  return ans;
}
inline int fnd(int l, int r) { return fnd(r) - fnd(l - 1); }
int main() {
  scanf("%d", &n);
  vector<int> X, Y;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%d%d", &mas[i].first, &mas[i].second);
    X.push_back(mas[i].first);
    Y.push_back(mas[i].second);
  }
  sort((X).begin(), (X).end());
  X.resize(unique((X).begin(), (X).end()) - X.begin());
  sort((Y).begin(), (Y).end());
  Y.resize(unique((Y).begin(), (Y).end()) - Y.begin());
  for (int _n((n)-1), i(0); i <= _n; i++) {
    mas[i].first =
        lower_bound((X).begin(), (X).end(), mas[i].first) - X.begin();
    mas[i].second =
        lower_bound((Y).begin(), (Y).end(), mas[i].second) - Y.begin();
  }
  sort(mas, mas + n, [](const pair<int, int>& a, const pair<int, int>& b) {
    return make_pair(-a.second, a.first) < make_pair(-b.second, b.first);
  });
  long long ans = 0;
  m = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    if (i && mas[i - 1].second == mas[i].second) continue;
    int b = i;
    while (b < n && mas[b].second == mas[i].second) ++b;
    for (int _n(b - 1), j(i + 1); j <= _n; j++) {
      if (j > i && mas[j].first == mas[j - 1].first) continue;
      int c = fnd(mas[j - 1].first + 1, mas[j].first - 1);
      ans -= (long long)c * (c + 1) / 2;
    }
    int c = fnd(mas[i].first - 1);
    ans -= (long long)c * (c + 1) / 2;
    c = fnd(mas[b - 1].first + 1, n);
    ans -= (long long)c * (c + 1) / 2;
    for (int _n(b - 1), j(i); j <= _n; j++) {
      int t = fnd(mas[j].first, mas[j].first);
      if (!t) {
        ++m;
        upd(mas[j].first, 1);
      }
    }
    ans += (long long)m * (m + 1) / 2;
  }
  cout << ans << endl;
}
