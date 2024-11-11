#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005], b[200005], c[200005], cnt[200005], pos1, pos2, ans[200005];
pair<int, int> p;
map<pair<int, int>, int> m1;
map<pair<int, int>, int> m2;
string s;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n - 2; i++) {
    cin >> a[i] >> b[i] >> c[i];
    cnt[a[i]]++;
    cnt[b[i]]++;
    cnt[c[i]]++;
    p.first = min(a[i], b[i]);
    p.second = max(a[i], b[i]);
    if (m1[p] == 0) {
      m1[p] = c[i];
    } else {
      m2[p] = c[i];
    }
    p.first = min(c[i], b[i]);
    p.second = max(c[i], b[i]);
    if (m1[p] == 0) {
      m1[p] = a[i];
    } else {
      m2[p] = a[i];
    }
    p.first = min(a[i], c[i]);
    p.second = max(a[i], c[i]);
    if (m1[p] == 0) {
      m1[p] = b[i];
    } else {
      m2[p] = b[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) {
      pos1 = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 2) {
      p.first = min(pos1, i);
      p.second = max(pos1, i);
      if (m1[p] > 0) {
        pos2 = i;
        break;
      }
    }
  }
  ans[1] = pos1;
  ans[2] = pos2;
  for (int i = 3; i <= n; i++) {
    if (i == 3) {
      p.first = min(ans[i - 2], ans[i - 1]);
      p.second = max(ans[i - 2], ans[i - 1]);
      ans[3] = m1[p];
    } else {
      p.first = min(ans[i - 2], ans[i - 1]);
      p.second = max(ans[i - 2], ans[i - 1]);
      if (m1[p] == ans[i - 3]) {
        ans[i] = m2[p];
      } else {
        ans[i] = m1[p];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
