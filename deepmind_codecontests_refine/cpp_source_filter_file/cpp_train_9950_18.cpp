#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
const long long INF = 1000 * 1000 * 1000;
long long pref[N], suff[N];
int main() {
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a;
  cin >> b;
  for (int i = 0; i < (int)b.size(); i++) pref[i] = INF, suff[i] = INF;
  for (int i = 0; i < (int)b.size(); i++) {
    int idx = (i == 0) ? 0 : pref[i - 1] + 1;
    while (idx < (int)a.size() && b[i] != a[idx]) idx++;
    if (idx >= (int)a.size())
      pref[i] = INF;
    else
      pref[i] = idx;
  }
  reverse((a).begin(), (a).end());
  reverse((b).begin(), (b).end());
  for (int i = 0; i < (int)b.size(); i++) {
    int idx = (i == 0) ? 0 : suff[i - 1] + 1;
    while (idx < (int)a.size() && b[i] != a[idx]) idx++;
    if (idx >= (int)a.size())
      suff[i] = INF;
    else
      suff[i] = idx;
  }
  reverse(suff, suff + (int)b.size());
  int l = (int)b.size() - 1, r = (int)b.size() - 1;
  bool ok = true;
  for (int i = 0; i < (int)b.size(); i++) {
    if (suff[i] != INF || pref[i] != INF) ok = false;
  }
  if (ok) return puts("-") * 0;
  while (l >= 0 && pref[l] == INF) l--;
  int maxlen = l + 1;
  int ansL = l, ansR = -1;
  while (l >= 0 && r >= 0 && suff[r] < INF) {
    while (r >= 0 && (int)b.size() - 1 - suff[r] > pref[l]) {
      int len = l + 1 + (int)b.size() - r;
      if (len > maxlen) {
        maxlen = len;
        ansL = l;
        ansR = r;
      }
      r--;
    }
    l--;
  }
  while (r >= 0 && (int)b.size() - 1 - suff[r] >= 0) {
    int len = l + 1 + (int)b.size() - r;
    if (len > maxlen) {
      maxlen = len;
      ansL = l;
      ansR = r;
    }
    r--;
  }
  reverse((b).begin(), (b).end());
  for (int i = 0; i <= ansL; i++) cout << b[i];
  if (ansR != -1)
    for (int i = ansR; i < (int)b.size(); i++) cout << b[i];
  cout << "\n";
  return 0;
}
