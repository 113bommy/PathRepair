#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e8;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const int N = 100;
int tonum(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return c - 'A' + 10;
}
int main() {
  ios::sync_with_stdio(false);
  string h, m;
  char c;
  while (1) {
    cin >> c;
    if (c == ':') {
      cin >> m;
      break;
    }
    h.push_back(c);
  }
  reverse(((h).begin()), ((h).end()));
  reverse(((m).begin()), ((m).end()));
  bool all = true;
  long long cnt = 0;
  for (int j = 0; j < ((int)((h).size())); ++j)
    cnt += pow(100, j) * tonum(h[j]);
  if (cnt > 23) all = false;
  cnt = 0;
  for (int j = 0; j < ((int)((m).size())); ++j)
    cnt += pow(100, j) * tonum(m[j]);
  if (cnt > 59) all = false;
  if (all) return cout << -1 << endl, 0;
  int maxi = 0;
  for (int i = 0; i < ((int)((h).size())); ++i)
    if (tonum(h[i]) > maxi) maxi = tonum(h[i]);
  for (int i = 0; i < ((int)((m).size())); ++i)
    if (tonum(m[i]) > maxi) maxi = tonum(m[i]);
  vector<int> ans;
  for (int i = (maxi + 1); i < (int)(61); ++i) {
    cnt = 0;
    for (int j = 0; j < ((int)((h).size())); ++j)
      cnt += pow(i, j) * tonum(h[j]);
    if (cnt > 23) continue;
    cnt = 0;
    for (int j = 0; j < ((int)((m).size())); ++j)
      cnt += pow(i, j) * tonum(m[j]);
    if (cnt > 59) continue;
    ans.push_back(i);
  }
  if (ans.size() == 0) return cout << 0 << endl, 0;
  for (int i = 0; i < ((int)((ans).size())); ++i) cout << ans[i] << " ";
  return 0;
}
