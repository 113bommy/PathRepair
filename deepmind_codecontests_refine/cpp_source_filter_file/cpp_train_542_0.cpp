#include <bits/stdc++.h>
using namespace std;
int n, q, le, ri, a[200100];
int max3[200100], max4[200100];
int ans3[200100][4], ans4[200100][5];
int st1[200100], st2[200100];
int cnt[200100];
int poi1, poi2, r1, r2, s1, s2;
int uu, vv;
set<int> s;
bool com1(int x, int y) { return a[x] < a[y]; }
bool com2(int x, int y) { return a[x] > a[y]; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  s.insert(n + 1);
  for (int i = n; i >= 1; i--) {
    while (poi1) {
      uu = st1[poi1];
      if (a[uu] > a[i]) {
        cnt[uu]--;
        poi1--;
        if (cnt[uu] == 0) s.insert(uu);
        r1 = 0;
      } else {
        break;
      }
    }
    while (poi2) {
      uu = st2[poi2];
      if (a[uu] < a[i]) {
        cnt[uu]--;
        poi2--;
        if (cnt[uu] == 0) s.insert(uu);
        r2 = 0;
      } else {
        break;
      }
    }
    s1 = lower_bound(st1 + 1, st1 + poi1 + 1, i, com1) - st1 - 1;
    s2 = lower_bound(st2 + 1, st2 + poi2 + 1, i, com2) - st1 - 1;
    max3[i] = i + max(r1, r2) + 1;
    ans3[i][1] = i;
    ans3[i][2] = max3[i] - 1;
    ans3[i][3] = max3[i];
    if (s1 && s2) {
      max4[i] = *s.lower_bound(max(st1[s1], st2[s2]));
      if (max4[i] <= n) {
        uu =
            lower_bound(st1 + 1, st1 + poi1 + 1, max4[i], greater<int>()) - st1;
        vv =
            lower_bound(st2 + 1, st2 + poi2 + 1, max4[i], greater<int>()) - st2;
        ans4[i][1] = i;
        ans4[i][2] = min(st1[uu], st2[vv]);
        ans4[i][3] = max(st1[uu], st2[vv]);
        ans4[i][4] = max4[i];
      }
    } else {
      max4[i] = n + 1;
    }
    st1[++poi1] = i;
    st2[++poi2] = i;
    r1++;
    r2++;
    cnt[i] += 2;
    if (i < n && max3[i + 1] < max3[i]) {
      max3[i] = max3[i + 1];
      for (int j = 1; j <= 3; j++) ans3[i][j] = ans3[i + 1][j];
    }
    if (i < n && max4[i + 1] < max4[i]) {
      max4[i] = max4[i + 1];
      for (int j = 1; j <= 4; j++) ans4[i][j] = ans4[i + 1][j];
    }
  }
  while (q--) {
    cin >> le >> ri;
    if (ri >= max4[le]) {
      cout << 4 << endl;
      for (int i = 1; i <= 4; i++) cout << ans4[le][i] << ' ';
      cout << endl;
    } else if (ri >= max3[le]) {
      cout << 3 << endl;
      for (int i = 1; i <= 3; i++) cout << ans3[le][i] << ' ';
      cout << endl;
    } else {
      cout << 0 << endl << endl;
    }
  }
  return 0;
}
