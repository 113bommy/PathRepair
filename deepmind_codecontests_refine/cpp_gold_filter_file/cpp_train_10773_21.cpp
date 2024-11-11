#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = (int)1e9 + 7;
const int MAXN = (int)1e6 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
string second;
int n;
int open, close;
int nxtPlus[MAXN];
int prvPlus[MAXN];
int nxtMult[MAXN];
int prvMult[MAXN];
bool inside(int pt, int l, int r) { return l <= pt && pt <= r; }
long long calc(int l, int r) {
  if (l == r) return second[l] - '0';
  bool flag = 0;
  if (l >= open && r <= close) {
    if (nxtPlus[l] <= r)
      return calc(l, nxtPlus[l] - 1) + calc(nxtPlus[l] + 1, r);
    else
      return calc(l, nxtMult[l] - 1) * calc(nxtMult[l] + 1, r);
  }
  if (!inside(nxtPlus[l], open, close) && nxtPlus[l] <= r)
    return calc(l, nxtPlus[l] - 1) + calc(nxtPlus[l] + 1, r);
  if (!inside(prvPlus[r], open, close) && prvPlus[r] >= l)
    return calc(l, prvPlus[r] - 1) + calc(prvPlus[r] + 1, r);
  if (!inside(nxtMult[l], open, close) && nxtMult[l] <= r)
    return calc(l, nxtMult[l] - 1) * calc(nxtMult[l] + 1, r);
  if (!inside(prvMult[r], open, close) && prvMult[r] >= l)
    return calc(l, prvMult[r] - 1) * calc(prvMult[r] + 1, r);
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> second;
  n = (int)second.size();
  prvMult[0] = -1;
  prvPlus[0] = -1;
  for (int i = 1; i < n; i++) {
    prvMult[i] = prvMult[i - 1];
    prvPlus[i] = prvPlus[i - 1];
    if (second[i] == '+') prvPlus[i] = i;
    if (second[i] == '*') prvMult[i] = i;
  }
  nxtMult[n - 1] = n;
  nxtPlus[n - 1] = n;
  for (int i = n - 2; i >= 0; i--) {
    nxtMult[i] = nxtMult[i + 1];
    nxtPlus[i] = nxtPlus[i + 1];
    if (second[i] == '+') nxtPlus[i] = i;
    if (second[i] == '*') nxtMult[i] = i;
  }
  long long ans = 0;
  for (int l = 0; l < n; l++) {
    if (second[l] == '*') {
      for (int r = l + 1; r < n; r++) {
        if (isdigit(second[r])) {
          open = l + 1;
          close = r;
          ans = max(ans, calc(0, n - 1));
        }
      }
    }
  }
  for (int r = 0; r < n; r++) {
    if (second[r] == '*') {
      for (int l = r - 1; l >= 0; l--) {
        if (isdigit(second[l])) {
          open = l;
          close = r - 1;
          ans = max(ans, calc(0, n - 1));
        }
      }
    }
  }
  ans = max(ans, calc(0, n - 1));
  cout << ans;
  return 0;
}
