#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<int, int> Min[20][N], Max[20][N];
int lg[N];
int n, a[N], m;
int lft[N], rgt[N];
int lft2[N];
int stk[N], top;
inline pair<int, int> qmx(int l, int r) {
  int g = lg[r - l + 1];
  return max(Max[g][l], Max[g][r - (1 << g) + 1]);
}
inline pair<int, int> qmn(int l, int r) {
  int g = lg[r - l + 1];
  return min(Min[g][l], Min[g][r - (1 << g) + 1]);
}
vector<pair<int, int> > q[N];
pair<int, int> R[N];
set<int> st;
int Rfour[N];
int ql[N], qr[N];
vector<int> F[N];
int LS[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), Min[0][i] = Max[0][i] = pair<int, int>(a[i], i);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; 1 << i <= n; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
      Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (mid == 0) l = mid;
      if (qmx(mid, i).first != a[i] && qmn(mid, i).first != a[i]) {
        l = mid;
      } else
        r = mid - 1;
    }
    lft[i] = l;
    l = i + 1, r = n + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (mid == n + 1) r = mid;
      if (qmx(i, mid).first != a[i] && qmn(i, mid).first != a[i]) {
        r = mid;
      } else
        l = mid + 1;
    }
    rgt[i] = l;
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    ql[i] = l, qr[i] = r;
    q[r].push_back(pair<int, int>(l, i));
  }
  pair<int, int> curres = pair<int, int>(0, 0);
  st.insert(0);
  for (int i = 1; i <= n; i++) {
    F[rgt[i]].push_back(i);
    for (size_t j = 0; j < F[i].size(); j++) {
      st.insert(F[i][j]);
    }
    set<int>::iterator s = st.upper_bound(lft[i]);
    --s;
    int Lft = *s;
    pair<int, int> temp = pair<int, int>(Lft, i);
    if (Lft > curres.first) curres = temp;
    for (size_t j = 0; j < q[i].size(); j++) {
      int L = q[i][j].first;
      if (L <= curres.first) {
        R[q[i][j].second] = curres;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (mid == 0) l = mid;
      if (qmx(mid, i).first != a[i]) {
        l = mid;
      } else
        r = mid - 1;
    }
    lft[i] = l;
    l = i + 1, r = n + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (mid == n + 1) r = mid;
      if (qmx(i, mid).first != a[i]) {
        r = mid;
      } else
        l = mid + 1;
    }
    rgt[i] = l;
    LS[rgt[i]] = max(LS[rgt[i]], lft[i]);
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, r = i - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (mid == 0) l = mid;
      if (qmn(mid, i).first != a[i]) {
        l = mid;
      } else
        r = mid - 1;
    }
    lft[i] = l;
    l = i + 1, r = n + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (mid == n + 1) r = mid;
      if (qmn(i, mid).first != a[i]) {
        r = mid;
      } else
        l = mid + 1;
    }
    rgt[i] = l;
    LS[rgt[i]] = max(LS[rgt[i]], lft[i]);
  }
  pair<int, int> Pair = pair<int, int>(0, 0);
  for (int i = 1; i <= n; i++) {
    if (LS[i] > Pair.first) Pair = pair<int, int>(LS[i], i);
    for (size_t j = 0; j < q[i].size(); j++) {
      if (R[q[i][j].second].first == 0) {
        int L = q[i][j].first;
        if (L <= Pair.first) {
          R[q[i][j].second] = Pair;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!R[i].first) {
      puts("0");
      puts("");
    } else {
      int p[4];
      bool t[4] = {1, 0, 0, 1};
      p[0] = R[i].first, p[1] = R[i].second,
      p[2] = qmx(R[i].first, R[i].second).second,
      p[3] = qmn(R[i].first, R[i].second).second;
      sort(p, p + 4);
      int ans = 0;
      if (a[p[2]] > a[p[0]] && a[p[2]] > a[p[3]]) t[2] = 1;
      if (a[p[2]] < a[p[0]] && a[p[2]] < a[p[3]]) t[2] = 1;
      if (a[p[1]] > a[p[0]] && a[p[1]] > a[p[3]]) t[1] = 1;
      if (a[p[1]] < a[p[0]] && a[p[1]] < a[p[3]]) t[1] = 1;
      for (int i = 0; i < 4; i++)
        if (t[i]) ans++;
      printf("%d\n", ans);
      for (int i = 0; i < 4; i++) {
        if (t[i]) printf("%d ", p[i]);
      }
      puts("");
    }
  }
}
