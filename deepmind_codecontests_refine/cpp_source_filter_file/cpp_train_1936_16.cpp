#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
;
const int inf = 1e9 + 5;
const int mod = 1e9 + 6;
const int logN = 17;
const int MX = 1e9 + 1;
int t, n, m, l, r, mx, ind, val, a[N];
int ST[N << 2], L[N << 2];
bool changed[N << 2];
pair<pair<int, int>, pair<int, int> > Q[N];
void init(int k, int bas, int son) {
  if (bas == son) {
    ST[k] = a[bas];
    return;
  }
  L[k] = MX;
  init((k + k), bas, (((bas) + (son)) / 2));
  init((k + k + 1), (((bas) + (son)) / 2) + 1, son);
  ST[k] = max(ST[(k + k)], ST[(k + k + 1)]);
}
void minimize(int k, int bas, int son, int l, int r, int val) {
  if (bas > r | son < l) {
    return;
  }
  if (l <= bas && son <= r) {
    if (changed[bas] && l == r) return;
    L[k] = min(L[k], val);
    ST[k] = min(ST[k], val);
    return;
  }
  if (L[k] < MX) {
    minimize((k + k), bas, (((bas) + (son)) / 2), bas, (((bas) + (son)) / 2),
             L[k]);
    minimize((k + k + 1), (((bas) + (son)) / 2) + 1, son,
             (((bas) + (son)) / 2) + 1, son, L[k]);
    L[k] = MX;
  }
  minimize((k + k), bas, (((bas) + (son)) / 2), l, r, val);
  minimize((k + k + 1), (((bas) + (son)) / 2) + 1, son, l, r, val);
  ST[k] = max(ST[(k + k)], ST[(k + k + 1)]);
}
void change(int k, int bas, int son, int ind, int val) {
  if (bas > ind | son < ind) {
    return;
  }
  if (bas == son) {
    ST[k] = val;
    return;
  }
  if (L[k] < MX) {
    minimize((k + k), bas, (((bas) + (son)) / 2), bas, (((bas) + (son)) / 2),
             L[k]);
    minimize((k + k + 1), (((bas) + (son)) / 2) + 1, son,
             (((bas) + (son)) / 2) + 1, son, L[k]);
    L[k] = MX;
  }
  change((k + k), bas, (((bas) + (son)) / 2), ind, val);
  change((k + k + 1), (((bas) + (son)) / 2) + 1, son, ind, val);
  ST[k] = max(ST[(k + k)], ST[(k + k + 1)]);
}
void relax(int k, int bas, int son) {
  if (bas == son) {
    if (changed[bas] == false) a[bas] = ST[k];
    return;
  }
  if (L[k] < MX) {
    minimize((k + k), bas, (((bas) + (son)) / 2), bas, (((bas) + (son)) / 2),
             L[k]);
    minimize((k + k + 1), (((bas) + (son)) / 2) + 1, son,
             (((bas) + (son)) / 2) + 1, son, L[k]);
    L[k] = MX;
  }
  relax((k + k), bas, (((bas) + (son)) / 2));
  relax((k + k + 1), (((bas) + (son)) / 2) + 1, son);
}
int query(int k, int bas, int son, int l, int r) {
  if (bas > r || son < l) {
    return 0;
  }
  if (l <= bas && son <= r) {
    return ST[k];
  }
  if (L[k] < MX) {
    minimize((k + k), bas, (((bas) + (son)) / 2), bas, (((bas) + (son)) / 2),
             L[k]);
    minimize((k + k + 1), (((bas) + (son)) / 2) + 1, son,
             (((bas) + (son)) / 2) + 1, son, L[k]);
    L[k] = MX;
  }
  return max(query((k + k), bas, (((bas) + (son)) / 2), l, r),
             query((k + k + 1), (((bas) + (son)) / 2) + 1, son, l, r));
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = MX;
  init(1, 1, n);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %d", &l, &r, &mx);
      minimize(1, 1, n, l, r, mx);
      Q[i] = make_pair(make_pair(t, l), make_pair(r, mx));
    } else {
      scanf("%d %d", &ind, &val);
      Q[i] = make_pair(make_pair(t, ind), make_pair(val, 0));
      if (!changed[ind]) {
        a[ind] = query(1, 1, n, ind, ind);
        changed[ind] = 1;
      }
    }
  }
  relax(1, 1, n);
  init(1, 1, n);
  for (int i = 1; i <= m; i++) {
    t = Q[i].first.first;
    if (t == 1) {
      l = Q[i].first.second, r = Q[i].second.first, mx = Q[i].second.second;
      int temp = query(1, 1, n, l, r);
      if (mx != temp) {
        puts("NO");
        return 0;
      }
    } else {
      ind = Q[i].first.second, val = Q[i].second.first;
      change(1, 1, n, ind, val);
    }
  }
  int ind1 = 0, ind2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == MX) {
      if (ind1)
        ind2 = i;
      else
        ind1 = i;
    }
  }
  if (ind1 && ind2) {
    a[ind1] = (1 << 29);
    a[ind2] = (1 << 29) - 1;
  } else {
    map<int, bool> H;
    int result = 0;
    for (int i = 1; i <= n; i++) {
      if (H[a[i]]) {
        int t = 0;
        while ((1 << (t + 1)) <= a[i]) t++;
        a[i] = (1 << t) - 1;
      } else {
        H[a[i]] = true;
      }
      if (i != ind1) result |= a[i];
    }
    if (ind1) {
      int left = MX - 1;
      for (int i = 29; i >= 0; i--) {
        if ((1 << i) <= left && ((result >> i) & 1) == 0) {
          left -= (1 << i);
          result += (1 << i);
        }
      }
      a[ind1] = MX - left;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    printf("%d", min(a[i], MX - 1));
    if (i != n)
      printf(" ");
    else
      puts("");
  }
  return 0;
}
