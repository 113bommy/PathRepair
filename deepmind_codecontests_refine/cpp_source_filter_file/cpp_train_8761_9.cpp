#include <bits/stdc++.h>
using namespace std;
const long long inf = 1791791791;
const long long mod = 1e9 + 7;
const int N = 5e6 + 5;
int v[N], o[N], sum[N];
set<int> s[2];
void q() {
  printf("once again\n");
  exit(0);
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  string st;
  cin >> st;
  for (int i = 0; i < n; i++) {
    o[i] = st[i] - '0';
    s[o[i]].insert(i + 1);
  }
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + o[i - 1];
  for (int i = k; i <= n; i++) {
    int ss = 0;
    ss += sum[n] - sum[k];
    ss += sum[k - i] - sum[0];
    if (ss == n - k || ss == 0) {
      printf("tokitsukaze\n");
      return 0;
    }
  }
  for (int i = k; i <= n; i++) {
    int q0 = 0, q1 = 0;
    int fs = i - k + 1, ed = i;
    auto it = s[0].begin();
    fs = min(fs, *it);
    it = s[0].end();
    it--;
    ed = max(ed, *it);
    if (ed - fs + 1 > k) q0++;
    fs = i - k + 1;
    ed = i;
    it = s[1].begin();
    fs = min(fs, *it);
    it = s[1].end();
    it--;
    ed = max(ed, *it);
    if (ed - fs + 1 > k) q1++;
    it = s[0].begin();
    if ((*it) >= i - k + 1 && (*it) <= i) {
      it = s[0].upper_bound(i);
    }
    fs = *it;
    it = s[0].end();
    it--;
    if ((*it) >= i - k + 1 && (*it) <= i) {
      it = s[0].lower_bound(i - k + 1);
      it--;
    }
    ed = *it;
    if (ed - fs + 1 > k) q1++;
    it = s[1].begin();
    if ((*it) >= i - k + 1 && (*it) <= i) {
      it = s[1].upper_bound(i);
    }
    fs = *it;
    it = s[1].end();
    it--;
    if ((*it) >= i - k + 1 && (*it) <= i) {
      it = s[1].lower_bound(i - k + 1);
      it--;
    }
    ed = *it;
    if (ed - fs + 1 > k) q0++;
    if (q0 == 2 || q1 == 2) {
      q();
    }
  }
  printf("quailty\n");
}
