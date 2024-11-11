#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
int n, k;
int A = 0;
int a[2 * MX];
int need[2 * MX];
void Print(int L) {
  printf("%d ", (L - 1) % n);
  for (int i = L; i < L + k; i++) printf("%d ", a[i]);
  printf("\n");
}
void Set(int i, int x) {
  if (i <= n) {
    a[i] = a[i + n] = x;
  } else {
    a[i] = a[i - n] = x;
  }
}
void SetNeed(int i, int x) {
  if (i <= n) {
    need[i] = need[i + n] = x;
  } else {
    need[i] = need[i - n] = x;
  }
}
void Do(int L, int R) {
  if (L > n) L -= n, R -= n;
  if (R - L + 1 <= k) {
    bool ok = true;
    for (int i = L; i <= R; i++) {
      if (a[i] != need[i]) ok = false;
      Set(i, need[i]);
    }
    if (ok) return;
    Print(L);
    return;
  }
  int s = 0;
  for (int i = L; i < L + k; i++) s += a[i];
  int x = 0;
  for (int i = L; i < L + (k - 1); i++) x += need[i];
  if (s >= x) {
    for (int i = L; i < L + (k - 1); i++) {
      Set(i, need[i]);
    }
    Set(L + k - 1, s - x);
    Print(L);
    Do(L + k - 1, R);
  } else {
    SetNeed(L + k - 1, a[L + k - 1] + need[L + k - 1] + x - s);
    Do(L + k - 1, R);
    for (int i = L; i < L + k; i++) {
      Set(i, A);
    }
    Set(L, need[L]);
    Print(L);
  }
}
int p[2 * MX];
map<int, vector<int>> M;
int up[2 * MX][20];
int last[2 * MX];
int main() {
  memset(up, -1, sizeof up);
  memset(last, -1, sizeof last);
  ignore = scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    ignore = scanf("%d", a + i);
    A += a[i];
  }
  A /= n;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i] - A;
    a[i + n] = a[i];
    p[i + n] = p[i];
    M[p[i]].push_back(i);
  }
  int ans = n;
  int from = 1;
  for (auto& P : M) {
    vector<int>& v = P.second;
    int m = (int)v.size();
    for (int i = 0; i < m; i++) v.push_back(v[i] + n);
    for (int i = (int)v.size() - 1; i >= 0; i--) {
      int t = v[i];
      up[t][0] = last[(t + 1) % (k - 1)];
      for (int j = 0; j + 1 < 20 && up[t][j] != -1; j++) {
        up[t][j + 1] = up[up[t][j]][j];
      }
      last[t % (k - 1)] = t;
    }
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      int t = v[i];
      for (int j = 19; j >= 0; j--) {
        if (up[t][j] == -1) continue;
        if (up[t][j] >= v[i] + n) continue;
        cnt += (up[t][j] - t - (1 << j)) / (k - 1);
        t = up[t][j];
      }
      cnt += (v[i] + n - t - 1 + (k - 2)) / (k - 1);
      if (cnt <= ans) {
        ans = cnt;
        from = v[i];
      }
    }
    for (int i = 0; i < (int)v.size(); i++) {
      for (int j = 0; j < 20; j++) up[v[i]][j] = -1;
      last[v[i] % (k - 1)] = -1;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= 2 * n; i++) need[i] = A;
  for (int i = from + 1, pr = from; i <= from + n; i++) {
    if (p[i] == p[pr] && (i == from + n || (i - pr - 1) % (k - 1) == 0)) {
      Do(pr + 1, i);
      pr = i;
    }
  }
}
