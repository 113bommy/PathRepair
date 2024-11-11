#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, m;
int t[N], l[N], r[N], x[N];
int arr[N];
int cnt = 0;
int seg[4 * N];
bool done[N];
int Mx;
int build(int s, int e, int idx) {
  if (s == e) return seg[idx] = arr[s];
  return seg[idx] = max(build(s, ((s + e) >> 1), (idx << 1)),
                        build(((s + e) >> 1) + 1, e, (idx << 1) + 1));
}
int L, R, val;
void update2(int s, int e, int idx) {
  if (s > R || e < L) return;
  if (s >= L && e <= R) {
    seg[idx] = min(seg[idx], val);
    return;
  }
  update2(s, ((s + e) >> 1), (idx << 1));
  update2(((s + e) >> 1) + 1, e, (idx << 1) + 1);
}
int get2(int i) {
  int s = 0, e = n - 1, res = Mx, idx = 1;
  while (true) {
    res = min(res, seg[idx]);
    if (s == e) break;
    if (i > ((s + e) >> 1)) {
      s = ((s + e) >> 1) + 1;
      idx = (idx << 1) + 1;
    } else {
      e = ((s + e) >> 1);
      idx = (idx << 1);
    }
  }
  return res;
}
int update(int s, int e, int idx) {
  if (s > R || e < L) return seg[idx];
  if (s == e) return seg[idx] = val;
  return seg[idx] = max(update(s, ((s + e) >> 1), (idx << 1)),
                        update(((s + e) >> 1) + 1, e, (idx << 1) + 1));
}
int getmax(int s, int e, int idx) {
  if (s > R || e < L) return 0;
  if (s >= L && e <= R) return seg[idx];
  return max(getmax(s, ((s + e) >> 1), (idx << 1)),
             getmax(((s + e) >> 1) + 1, e, (idx << 1) + 1));
}
bool check(int Val) {
  Mx = Val;
  for (int i = 0; i < n; i++) arr[i] = Val, done[i] = false;
  build(0, n - 1, 1);
  for (int i = 0; i < m; i++) {
    if (t[i] == 2) {
      if (done[l[i]]) continue;
      arr[l[i]] = get2(l[i]);
      done[l[i]] = true;
      continue;
    }
    L = l[i], R = r[i], val = x[i];
    update2(0, n - 1, 1);
  }
  for (int i = 0; i < n; i++) {
    if (!done[i]) arr[i] = get2(i);
  }
  build(0, n - 1, 1);
  for (int i = 0; i < m; i++) {
    if (t[i] == 2) {
      L = R = l[i];
      val = x[i];
      update(0, n - 1, 1);
    } else {
      L = l[i], R = r[i];
      if (getmax(0, n - 1, 1) != x[i]) return false;
    }
  }
  return true;
}
map<int, bool> Done;
inline int get(int val) {
  for (int i = 29; i >= 0; i--) {
    if (((val >> i) & 1) == 1) return (1 << i) - 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &t[i], &l[i], &r[i]);
    if (t[i] == 1) {
      l[i]--, r[i]--;
      scanf("%d", &x[i]);
    } else {
      x[i] = r[i];
      l[i]--;
      r[i] = l[i];
    }
  }
  int val = (int)1e9 + 1;
  if (!check(val)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) continue;
    if (Done[arr[i]]) {
      arr[i] = get(arr[i]);
      continue;
    }
    Done[arr[i]] = true;
  }
  int o = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == val) {
      continue;
    }
    o |= arr[i];
  }
  o ^= ((1 << 30) - 1);
  for (int i = 0; i < n; i++) {
    if (arr[i] != val) continue;
    arr[i] = 0;
    for (int j = 29; j >= 0; j--) {
      if (((o >> j) & 1) == 0) continue;
      if ((arr[i] ^ (1 << j)) >= val) continue;
      arr[i] ^= (1 << j);
      o ^= (1 << j);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", arr[i]);
  }
  puts("");
  return 0;
}
