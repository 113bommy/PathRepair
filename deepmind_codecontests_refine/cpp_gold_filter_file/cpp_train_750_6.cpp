#include <bits/stdc++.h>
using namespace std;
int T, N, mxc, t[400400], nxt[200200];
char s[200200];
set<int> all, h[28];
vector<pair<int, int>> res;
void u(int l, int r, int v) {
  for (l += N, r += N; l < r; l /= 2, r /= 2) {
    if (l & 1) t[l++] += v;
    if (r & 1) t[--r] += v;
  }
}
int q(int i) {
  int result = 0;
  for (i += N; i >= 1; i /= 2) result += t[i];
  return result;
}
void rem(int i) {
  all.erase(i);
  h[s[i] - 'a'].erase(i);
}
void proc(int i, int j) {
  int na = q(nxt[i]), nb = q(j);
  res.push_back(make_pair(1 + na, 1 + nb));
  u(j, N, -(nb - na + 1));
  if (s[nxt[i]] == s[j])
    rem(j);
  else
    rem(i), rem(j);
  nxt[i] = nxt[j];
}
int main() {
  scanf("%d", &T);
  for (int z = (0); z < (T); z++) {
    scanf("%s", s);
    N = (int)strlen(s);
    for (int i = (0); i < (N); i++) {
      nxt[i] = i + 1;
      t[i + N] = i;
      t[i] = 0;
    }
    res.clear();
    all.clear();
    for (int i = (0); i < (28); i++) h[i].clear();
    for (int i = (0); i < (N - 1); i++) {
      if (s[i] == s[i + 1]) {
        all.insert(i);
        h[s[i] - 'a'].insert(i);
      }
    }
    mxc = 0;
    for (int i = (0); i < (28); i++) {
      if (((int)h[i].size()) > ((int)h[mxc].size())) {
        mxc = i;
      }
    }
    int expected = max(((int)h[mxc].size()), (((int)all.size()) + 1) / 2);
    while (all.size()) {
      if (((int)all.size()) == 1) {
        int f = *all.begin();
        res.push_back(make_pair(1 + q(f), 1 + q(f)));
        u(f, N, -1);
        rem(f);
        break;
      }
      for (int i = (0); i < (28); i++) {
        if (((int)h[i].size()) > ((int)h[mxc].size())) {
          mxc = i;
        }
      }
      if (*h[mxc].begin() == *all.begin()) {
        int mni = N;
        for (int i = (0); i < (28); i++)
          if (i != mxc && h[i].size()) {
            mni = min(mni, *h[i].begin());
          }
        if (mni == N) {
          proc(*h[mxc].begin(), *next(h[mxc].begin()));
        } else {
          auto x = *prev(h[mxc].lower_bound(mni));
          proc(x, mni);
        }
      } else {
        int first_big = *h[mxc].begin();
        auto it = all.lower_bound(first_big);
        proc(*prev(it), *it);
      }
    }
    if (q(N - 1) >= 0) res.push_back(make_pair(1, q(N - 1) + 1));
    printf("%d\n", ((int)res.size()));
    for (auto i : res) printf("%d %d\n", i.first, i.second);
  }
  return 0;
}
