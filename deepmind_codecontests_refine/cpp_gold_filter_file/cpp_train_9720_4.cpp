#include <bits/stdc++.h>
using namespace std;
vector<int> H, S;
int time(int k) {
  int ih = 0, is = 0;
  int hs = H.size();
  int t = H[0] + 1;
  while (ih != hs) {
    if (k) {
      --k;
      ++ih;
      if (ih == hs) break;
      t += H[ih] - H[ih - 1];
    } else if (S[is] < H[ih]) {
      ++is;
      ++ih;
      if (ih == hs) break;
      t += H[ih] - H[ih - 1];
    } else {
      int indh = ih;
      for (; ih < hs - 1; ++ih, ++is)
        if (H[ih + 1] > S[is]) break;
      int dist = S[is] - H[indh];
      t += 2 * dist;
      ++ih;
      if (ih == hs) break;
      t += H[ih] - H[indh];
      ++is;
    }
  }
  return t;
}
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  string road;
  cin >> road;
  for (int i = 0; i < n; ++i) {
    if (road[i] == 'H') {
      H.push_back(i);
    }
    if (road[i] == 'S') {
      S.push_back(i);
    }
  }
  int hs = H.size(), is = S.size();
  int res = -1, s = max(0, hs - is), e = 1000000;
  while (s <= e) {
    int mid = (s + e) / 2;
    int tt = min(2 * n - 1, time(mid));
    if (tt <= t) {
      res = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  printf("%d\n", res);
  return 0;
}
