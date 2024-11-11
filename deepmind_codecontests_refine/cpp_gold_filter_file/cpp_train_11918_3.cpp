#include <bits/stdc++.h>
using namespace std;
typedef struct {
  long long le;
  long long ri;
  long long ans;
} Struct;
long long n, m, l, r, idx, L, R, val, dist[200001], h[200001], pref[200001];
Struct st, SegTree[800001];
void upd(long long low, long long high, long long pos) {
  if (idx < low || idx > high) return;
  if (idx == low && low == high) {
    SegTree[pos].le = 2 * h[low] - val;
    SegTree[pos].ri = 2 * h[low] + val;
    return;
  }
  long long mid = (low + high) / 2;
  upd(low, mid, 2 * pos);
  upd(mid + 1, high, 2 * pos + 1);
  long long left = SegTree[2 * pos].le + SegTree[2 * pos + 1].ri;
  SegTree[pos].le = max(SegTree[2 * pos].le, SegTree[2 * pos + 1].le);
  SegTree[pos].ri = max(SegTree[2 * pos].ri, SegTree[2 * pos + 1].ri);
  SegTree[pos].ans =
      max(max(SegTree[2 * pos].ans, SegTree[2 * pos + 1].ans), left);
}
Struct get(long long low, long long high, long long pos) {
  if (L > high || R < low) return st;
  if (L <= low && R >= high) return SegTree[pos];
  long long mid = (low + high) / 2;
  Struct s1 = get(low, mid, 2 * pos);
  Struct s2 = get(mid + 1, high, 2 * pos + 1);
  Struct s3;
  long long left = s1.le + s2.ri;
  s3.le = max(s1.le, s2.le);
  s3.ri = max(s1.ri, s2.ri);
  s3.ans = max(max(s1.ans, s2.ans), left);
  return s3;
}
int main() {
  st.le = st.ri = st.ans = -10000000000000000;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> dist[i];
    pref[i] = pref[i - 1] + dist[i - 1];
    dist[i + n] = dist[i];
  }
  for (long long i = n + 1; i <= 2 * n; i++)
    pref[i] = pref[i - 1] + dist[i - 1];
  for (long long i = 1; i <= n; i++) {
    cin >> h[i];
    h[i + n] = h[i];
  }
  for (long long i = 1; i <= 2 * n; i++) {
    val = pref[i];
    idx = i;
    upd(1, 2 * n, 1);
  }
  for (long long i = 1; i <= m; i++) {
    cin >> l >> r;
    Struct ANS;
    if (l > r) {
      R = l - 1, L = r + 1;
      if (L <= R) ANS = get(1, 2 * n, 1);
    } else {
      R = l - 1 + n;
      L = r + 1;
      if (L <= R) ANS = get(1, 2 * n, 1);
    }
    cout << ANS.ans << endl;
  }
}
