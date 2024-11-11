#include <bits/stdc++.h>
using namespace std;
const long long lim = 1000 + 9;
int cnt[603];
int mn[603], pos[603];
int main() {
  memset(mn, -1, sizeof mn);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    int val = 0;
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      x--;
      val |= (1 << x);
    }
    cnt[val]++;
  }
  vector<pair<int, int> > price;
  for (int i = 0; i < q; i++) {
    int c, m;
    scanf("%d %d", &c, &m);
    price.push_back(make_pair(c, i + 1));
    int val = 0;
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      x--;
      val |= (1 << x);
    }
    if (mn[val] != -1) {
      if (c < mn[val]) mn[val] = c, pos[val] = i + 1;
    } else
      mn[val] = c, pos[val] = i + 1;
  }
  int mx = 0, ans1 = -1, ans2 = -1, mnconst = INT_MAX;
  sort(price.begin(), price.end());
  for (int a = 1; a <= 513; a++) {
    if (mn[a] == -1) continue;
    int tem = 0;
    for (int b = 1; b <= 513; b++) {
      if (mn[b] == -1) continue;
      tem = 0;
      if (pos[a] == pos[b]) continue;
      for (int f = 1; f <= 513; f++) {
        if (cnt[f] == 0) continue;
        if ((f & (a | b)) > f) tem += cnt[f];
      }
      if (tem > mx)
        mx = tem, ans1 = pos[a], ans2 = pos[b], mnconst = mn[a] + mn[b];
      else if (tem == mx) {
        if (mn[a] + mn[b] < mnconst)
          mx = tem, ans1 = pos[a], ans2 = pos[b], mnconst = mn[a] + mn[b];
      }
    }
    tem = 0;
    for (int f = 1; f <= 513; f++) {
      if (cnt[f] == 0) continue;
      if (((f & a) >= f)) tem += cnt[f];
    }
    int g, ind;
    if (price[0].second == pos[a])
      g = price[1].first, ind = price[1].second;
    else
      g = price[0].first, ind = price[0].second;
    if (tem >= mx) {
      if (mn[a] + g < mnconst)
        mx = tem, ans1 = pos[a], ans2 = ind, mnconst = mn[a] + g;
    }
  }
  cout << ans1 << " " << ans2 << endl;
}
