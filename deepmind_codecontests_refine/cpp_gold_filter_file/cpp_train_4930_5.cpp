#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000005, INF = 0x3f3f3f3f;
int A[NMAX];
int pleft[NMAX], pright[NMAX];
int stk[NMAX];
pair<int, int> len[NMAX], l[NMAX], r[NMAX];
long double sumLen[NMAX], sumL[NMAX], sumR[NMAX];
long double coefLen[NMAX], coefL[NMAX], coefR[NMAX];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  int top = 1;
  stk[0] = 0;
  for (int i = 1; i <= n; ++i) {
    while (A[i] < A[stk[top - 1]]) {
      top--;
    }
    pleft[i] = stk[top - 1];
    stk[top++] = i;
  }
  top = 1;
  stk[0] = n + 1;
  for (int i = n; i > 0; --i) {
    while (A[i] <= A[stk[top - 1]]) {
      top--;
    }
    pright[i] = stk[top - 1];
    stk[top++] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int clen = pright[i] - pleft[i] - 1;
    int cl = i - pleft[i] - 1;
    int cr = pright[i] - i - 1;
    len[i] = make_pair(clen, A[i]);
    l[i] = make_pair(cl, A[i]);
    r[i] = make_pair(cr, A[i]);
  }
  sort(len + 1, len + n + 1);
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  for (int i = n; i > 0; --i) {
    sumLen[i] = sumLen[i + 1] + len[i].second;
    sumL[i] = sumL[i + 1] + l[i].second;
    sumR[i] = sumR[i + 1] + r[i].second;
    coefLen[i] = coefLen[i + 1] + (long double)len[i].second * len[i].first;
    coefL[i] = coefL[i + 1] + (long double)l[i].second * l[i].first;
    coefR[i] = coefR[i + 1] + (long double)r[i].second * r[i].first;
  }
  int q;
  cin >> q;
  while (q-- > 0) {
    int k;
    cin >> k;
    int pos;
    long double ans = 0;
    pos = lower_bound(len + 1, len + n + 1, make_pair(k, -1)) - len;
    ans += coefLen[pos] - sumLen[pos] * k + sumLen[pos];
    pos = lower_bound(l + 1, l + n + 1, make_pair(k, -1)) - l;
    ans -= coefL[pos] - sumL[pos] * k + sumL[pos];
    pos = lower_bound(r + 1, r + n + 1, make_pair(k, -1)) - r;
    ans -= coefR[pos] - sumR[pos] * k + sumR[pos];
    ans /= (n - k + 1);
    printf("%.17f\n", (double)ans);
  }
}
