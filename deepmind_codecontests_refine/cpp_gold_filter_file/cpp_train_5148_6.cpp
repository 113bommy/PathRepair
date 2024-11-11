#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
inline void smin(P &a, Q b) {
  if (b < a) a = b;
}
template <class P, class Q>
inline void smax(P &a, Q b) {
  if (a < b) a = b;
}
const int maxn = 50000 + 100;
const int maxl = 4;
const int cnts = 26 + 26 * 26 + 26 * 26 * 26 + 26 * 26 * 26 * 26;
const int thr = 200;
const int maxg = maxn / thr * maxl;
const int inf = 1 << 29;
int n;
string ss;
int s[maxn];
vector<int> p[cnts];
vector<int> big;
int bid[cnts];
int last[cnts];
int ans[maxg][maxg];
int getid(int *st, int *ed) {
  int len = ed - st;
  int res = 0;
  if (len > 1) res += 26;
  if (len > 2) res += 26 * 26;
  if (len > 3) res += 26 * 26 * 26;
  int mul = 1;
  while (st < ed) res += mul * (*st), st++, mul *= 26;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> ss;
  n = (int((ss).size()));
  for (int i = 0, _n = (int)(n); i < _n; i++) s[i] = ss[i] - 'a';
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int len = (int)(1), _n = (int)(5); len < _n; len++)
      if (i + len <= n) p[getid(s + i, s + i + len)].push_back(i);
  memset(bid, -1, sizeof bid);
  for (int i = 0, _n = (int)(cnts); i < _n; i++)
    if ((int((p[i]).size())) >= thr) {
      bid[i] = (int((big).size()));
      big.push_back(i);
    }
  memset(ans, 50, sizeof ans);
  memset(last, -50, sizeof last);
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int len = (int)(1), _n = (int)(5); len < _n; len++)
      if (i + len <= n) {
        int id = getid(s + i, s + i + len);
        if (bid[id] == -1) continue;
        for (int x : big)
          if (x != id && last[x] >= 0)
            smin(ans[bid[x]][bid[id]], i + len - last[x]);
        last[id] = i;
      }
  int qc;
  cin >> qc;
  while (qc--) {
    string ss1, ss2;
    cin >> ss1 >> ss2;
    int n1 = (int((ss1).size())), n2 = (int((ss2).size()));
    int s1[5], s2[5];
    for (int i = 0, _n = (int)(n1); i < _n; i++) s1[i] = ss1[i] - 'a';
    for (int i = 0, _n = (int)(n2); i < _n; i++) s2[i] = ss2[i] - 'a';
    int id1 = getid(s1, s1 + n1);
    int id2 = getid(s2, s2 + n2);
    if ((int((p[id1]).size())) > (int((p[id2]).size())))
      swap(id1, id2), swap(n1, n2);
    if ((int((p[id1]).size())) >= thr) {
      if (id1 == id2)
        cout << n1 << endl;
      else
        cout << max(min(ans[bid[id1]][bid[id2]], ans[bid[id2]][bid[id1]]),
                    max(n1, n2))
             << endl;
    } else {
      int res = inf;
      vector<int> &v = p[id2];
      for (int pos1 : p[id1]) {
        int tmp = lower_bound((v).begin(), (v).end(), pos1) - v.begin();
        if (tmp < (int((v).size()))) smin(res, v[tmp] + n2 - pos1);
        if (tmp) tmp--, smin(res, pos1 + n1 - v[tmp]);
      }
      if (res == inf)
        cout << -1 << endl;
      else
        cout << max(res, max(n1, n2)) << endl;
    }
  }
  { return 0; }
}
