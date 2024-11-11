#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int n;
int pref[N];
int a[N], q[N];
int c = 2 * 1000 * 100;
int L, R, M;
int answ;
int t[4 * N];
void update(int v, int s, int e, int pos) {
  if (s == e) {
    ++t[v];
    return;
  }
  int m = (s + e) / 2;
  if (pos <= m)
    update(2 * v, s, m, pos);
  else
    update(2 * v + 1, m + 1, e, pos);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}
int get(int v, int s, int e, int l, int r) {
  if (l > r) return 0;
  if (s == l && e == r) return t[v];
  int m = (s + e) / 2;
  return min(get(2 * v, s, m, l, min(r, m)),
             get(2 * v + 1, m + 1, e, max(m + 1, l), r));
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(1, 1, c, a[i]);
    ++q[a[i]];
  }
  for (int i = 1; i <= c; i++) {
    pref[i] = pref[i - 1] + q[i];
  }
  for (int i = 1; i <= c; i++) {
    if (q[i] == 0) continue;
    int ina = 1, inb = i - 1;
    int l = i;
    while (ina <= inb) {
      int mid = (ina + inb) / 2;
      if (get(1, 1, c, mid, i - 1) >= 2) {
        l = mid;
        inb = mid - 1;
      } else
        ina = mid + 1;
    }
    int r = i;
    ina = i + 1;
    inb = c;
    while (ina <= inb) {
      int mid = (ina + inb) / 2;
      if (get(1, 1, c, i + 1, mid) >= 2) {
        r = mid;
        ina = mid + 1;
      } else
        inb = mid - 1;
    }
    if (q[l - 1]) l--;
    if (q[r + 1]) r++;
    if (q[i] == 1) {
      int s = pref[i] - pref[l - 1];
      if (s > answ) {
        answ = s;
        L = l;
        R = i;
        M = i;
      }
      s = pref[r] - pref[i - 1];
      if (s > answ) {
        answ = s;
        L = i;
        R = r;
        M = i;
      }
    } else {
      int s = pref[r] - pref[l - 1];
      if (s > answ) {
        answ = s;
        L = l;
        R = r;
        M = i;
      }
    }
  }
  cout << answ << endl;
  for (int i = M; i >= L; i--) {
    printf("%d ", i);
    --q[i];
  }
  for (int i = L; i <= M; i++) {
    if (i != L) assert(q[i] != 0);
    while (q[i]--) {
      printf("%d ", i);
    }
  }
  for (int i = M + 1; i <= R; i++) {
    printf("%d ", i);
    --q[i];
  }
  for (int i = R; i >= M + 1; i--) {
    if (i != R) assert(q[i] != 0);
    while (q[i]--) {
      printf("%d ", i);
    }
  }
  cout << endl;
  return 0;
}
