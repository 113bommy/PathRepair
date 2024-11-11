#include <bits/stdc++.h>
using namespace std;
long long s[2000500], sum[2000500];
void add(int l, int r, int nl, int nr, int cur, long long ad) {
  if (l == nl && r == nr) {
    sum[cur] = (sum[cur] + ad);
    s[cur] = (s[cur] + ad * (r - l + 1));
    if (l != r && sum[cur]) {
      sum[(cur << 1)] = (sum[(cur << 1)] + sum[cur]);
      s[(cur << 1)] = (s[(cur << 1)] + sum[cur] * (((l + r) >> 1) - l + 1));
      sum[((cur << 1) + 1)] = (sum[((cur << 1) + 1)] + sum[cur]);
      s[((cur << 1) + 1)] =
          (s[((cur << 1) + 1)] + sum[cur] * (r - ((l + r) >> 1)));
      sum[cur] = 0;
    };
    return;
  }
  if (l != r && sum[cur]) {
    sum[(cur << 1)] = (sum[(cur << 1)] + sum[cur]);
    s[(cur << 1)] = (s[(cur << 1)] + sum[cur] * (((l + r) >> 1) - l + 1));
    sum[((cur << 1) + 1)] = (sum[((cur << 1) + 1)] + sum[cur]);
    s[((cur << 1) + 1)] =
        (s[((cur << 1) + 1)] + sum[cur] * (r - ((l + r) >> 1)));
    sum[cur] = 0;
  };
  if (nr <= ((l + r) >> 1)) {
    add(l, ((l + r) >> 1), nl, nr, (cur << 1), ad);
  } else {
    if (nl > ((l + r) >> 1)) {
      add(((l + r) >> 1) + 1, r, nl, nr, ((cur << 1) + 1), ad);
    } else {
      add(l, ((l + r) >> 1), nl, ((l + r) >> 1), (cur << 1), ad);
      add(((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, nr, ((cur << 1) + 1), ad);
    }
  }
  s[cur] = (s[(cur << 1)] + s[((cur << 1) + 1)]);
}
long long ask(int l, int r, int nl, int nr, int cur) {
  if (l != r && sum[cur]) {
    sum[(cur << 1)] = (sum[(cur << 1)] + sum[cur]);
    s[(cur << 1)] = (s[(cur << 1)] + sum[cur] * (((l + r) >> 1) - l + 1));
    sum[((cur << 1) + 1)] = (sum[((cur << 1) + 1)] + sum[cur]);
    s[((cur << 1) + 1)] =
        (s[((cur << 1) + 1)] + sum[cur] * (r - ((l + r) >> 1)));
    sum[cur] = 0;
  };
  if (l == nl && r == nr) {
    return s[cur];
  }
  if (nr <= ((l + r) >> 1)) {
    return ask(l, ((l + r) >> 1), nl, nr, (cur << 1));
  }
  if (nl > ((l + r) >> 1)) {
    return ask(((l + r) >> 1) + 1, r, nl, nr, ((cur << 1) + 1));
  }
  return ask(l, ((l + r) >> 1), nl, ((l + r) >> 1), (cur << 1)) +
         ask(((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, nr, ((cur << 1) + 1));
}
int i, j, k, l, r, n, m, t, a[200500], sb, tmp;
set<int> st;
int main() {
  scanf("%d%d", &n, &t);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  st.insert(n + 1);
  st.insert(1);
  st.insert(0);
  for (i = 1; i <= n; i++) {
    if (a[i] >= a[i - 1]) {
      k++;
    } else {
      k = 1;
      st.insert(i);
    }
    add(1, n, i, i, 1, k);
  }
  while (t--) {
    scanf("%d", &sb);
    if (sb == 1) {
      scanf("%d%d", &j, &k);
      auto it = st.upper_bound(j);
      r = *it - 1;
      it--;
      l = *it;
      a[j] = k;
      if (j == 1) {
        goto aaa;
      }
      if (a[j - 1] <= a[j]) {
        if (l == j) {
          tmp = ask(1, n, j - 1, j - 1, 1);
          add(1, n, j, r, 1, tmp);
          st.erase(l);
        }
      } else {
        if (l != j) {
          tmp = ask(1, n, j - 1, j - 1, 1);
          add(1, n, j, r, 1, -tmp);
          st.insert(j);
        }
      }
    aaa:;
      if (j == n) {
        goto bbb;
      }
      it = st.upper_bound(j);
      r = *it - 1;
      it--;
      l = *it;
      if (a[j] <= a[j + 1]) {
        if (r == j) {
          tmp = ask(1, n, j, j, 1);
          add(1, n, j + 1, *st.upper_bound(j + 1) - 1, 1, tmp);
          st.erase(j + 1);
        }
      } else {
        if (r != j) {
          tmp = ask(1, n, j, j, 1);
          add(1, n, j + 1, r, 1, -tmp);
          st.insert(j + 1);
        }
      }
    bbb:;
    } else {
      scanf("%d%d", &j, &k);
      auto it = st.upper_bound(k);
      it--;
      if (*it <= j) {
        long long sb = k - j + 1;
        printf("%lld\n", sb * (sb + 1) / 2);
        continue;
      }
      r = *it;
      it = st.lower_bound(j);
      l = *it;
      long long ans = ask(1, n, j, k, 1);
      if (l > j) {
        ans -= ask(1, n, j, l - 1, 1);
        long long sb = l - j;
        ans += (sb * sb + sb) / 2;
      }
      printf("%lld\n", ans);
    }
  }
}
