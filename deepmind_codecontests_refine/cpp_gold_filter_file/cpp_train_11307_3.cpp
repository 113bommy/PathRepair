#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    T f = x % y;
    x = y;
    y = f;
  }
  return x;
}
const int maxn = 100007;
int BLOCKSIZE = 350;
set<int> s[maxn];
int a[maxn];
int nxt[maxn];
int n, m;
long long b[maxn];
int d[maxn];
long long query(int block, int R) {
  int iBlockStart = block * BLOCKSIZE;
  int iBlockEnd = min((block + 1) * BLOCKSIZE, n);
  int idx = upper_bound(d + iBlockStart, d + iBlockEnd, R,
                        [](int i, int j) { return i < nxt[j]; }) -
            d;
  if (idx == iBlockStart) return 0;
  return b[idx - 1];
}
void updateBlock(int block) {
  int iBlockStart = block * BLOCKSIZE;
  int iBlockEnd = min((block + 1) * BLOCKSIZE, n);
  sort(d + iBlockStart, d + iBlockEnd,
       [](int i, int j) { return nxt[i] < nxt[j]; });
  b[iBlockStart] = nxt[d[iBlockStart]] - d[iBlockStart];
  for (int i = iBlockStart + 1; i < iBlockEnd; i++)
    b[i] = b[i - 1] + nxt[d[i]] - d[i];
}
int main(int argc, char *argv[]) {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m;
  {
    BLOCKSIZE = 1;
    while (BLOCKSIZE * BLOCKSIZE < n) BLOCKSIZE++;
    BLOCKSIZE = max(BLOCKSIZE, 10);
    for (int i = 0; i < n; i++) nxt[i] = n + 1, d[i] = i;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!s[a[i]].empty()) nxt[*s[a[i]].rbegin()] = i;
      s[a[i]].insert(i);
    }
    for (int i = 0; i * BLOCKSIZE < n; i++) updateBlock(i);
    for (int i = 0; i < m; i++) {
      int op;
      cin >> op;
      if (op == 1) {
        int p, x;
        cin >> p >> x;
        p--;
        if (a[p] == x) continue;
        {
          auto it = s[a[p]].find(p);
          if (it != s[a[p]].begin()) {
            int pr = *prev(it);
            auto nxt_it = it == s[a[p]].end() ? it : next(it);
            nxt[pr] = nxt_it == s[a[p]].end() ? (n + 1) : *nxt_it;
            updateBlock(pr / BLOCKSIZE);
          }
        }
        s[a[p]].erase(p);
        a[p] = x;
        nxt[p] = n + 1;
        if (!s[x].empty()) {
          auto it = s[x].upper_bound(p);
          if (it != s[x].begin()) {
            int pr = *prev(it);
            nxt[pr] = p;
            updateBlock(pr / BLOCKSIZE);
          }
          if (it != s[x].end()) {
            nxt[p] = (it == s[x].end()) ? (n + 1) : *it;
          }
        }
        s[a[p]].insert(p);
        updateBlock(p / BLOCKSIZE);
      } else {
        int l, r, R;
        cin >> l >> r;
        l--;
        r--;
        R = r;
        long long res = 0;
        for (; l <= r && l % BLOCKSIZE; l++)
          if (nxt[l] <= R) res += nxt[l] - l;
        for (; l <= r && (r + 1) % BLOCKSIZE; r--)
          if (nxt[r] <= R) res += nxt[r] - r;
        if (l <= r) {
          for (int i = l / BLOCKSIZE, j = r / BLOCKSIZE; i <= j; i++) {
            res += query(i, R);
          }
        }
        cout << res << endl;
      }
    }
  }
  return 0;
}
