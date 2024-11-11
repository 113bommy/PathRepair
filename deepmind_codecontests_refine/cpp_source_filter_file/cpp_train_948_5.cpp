#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
struct Move {
  int from, to, kind;
  Move() {}
  Move(int from, int to, int kind) : from(from), to(to), kind(kind) {}
};
int n, nkind;
vector<int> have[MAXN];
vector<Move> ans;
pair<int, int> o[MAXN];
int want[MAXN];
vector<int> calccanmove(vector<int> &a, vector<int> &b, int need) {
  vector<int> ret;
  int at = ((int)(b).size()) - 1;
  for (int i = ((int)(a).size()) - 1; i >= 0 && ((int)(ret).size()) < need;
       --i) {
    while (at >= 0 && b[at] > a[i]) --at;
    if (at >= 0 && b[at] == a[i]) continue;
    ret.push_back(a[i]);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
void remove(vector<int> &a, vector<int> &b) {
  if (((int)(b).size()) == 0) return;
  int idx = ((int)(a).size()) - 1;
  while (idx >= 0 && a[idx] >= b[0]) --idx;
  int n = idx;
  for (int i = (0); i < (((int)(b).size())); ++i) {
    while (idx < ((int)(a).size()) && a[idx] < b[i]) a[n++] = a[idx++];
    assert(idx < ((int)(a).size()) && a[idx] == b[i]);
    ++idx;
  }
  while (idx < ((int)(a).size())) a[n++] = a[idx++];
  a.resize(n);
}
vector<int> merge(vector<int> &a, vector<int> &b) {
  vector<int> ret;
  int ai = 0, bi = 0;
  while (ai < ((int)(a).size()) || bi < ((int)(b).size())) {
    if (ai < ((int)(a).size()) && (bi > ((int)(b).size()) || a[ai] <= b[bi]))
      ret.push_back(a[ai++]);
    else
      ret.push_back(b[bi++]);
  }
  return ret;
}
void solve() {
  for (int i = (0); i < (n); ++i) sort(have[i].begin(), have[i].end());
  for (int i = (0); i < (n); ++i) o[i] = make_pair(((int)(have[i]).size()), i);
  sort(o, o + n);
  int tothave = 0;
  for (int i = (0); i < (n); ++i) tothave += ((int)(have[i]).size());
  int each = tothave / n, extra = tothave % n;
  for (int i = (0); i < (n); ++i) want[i] = each;
  for (int i = 0; i < extra; ++i) ++want[n - i - 1];
  ans.clear();
  int lidx = 0, ridx = n - 1;
  while (lidx < ridx) {
    int l = o[lidx].second, r = o[ridx].second;
    if (((int)(have[l]).size()) >= want[lidx]) {
      ++lidx;
      continue;
    }
    if (((int)(have[r]).size()) <= want[ridx]) {
      --ridx;
      continue;
    }
    int nmove = min(want[lidx] - ((int)(have[l]).size()),
                    ((int)(have[r]).size()) - want[ridx]);
    vector<int> tomove = calccanmove(have[r], have[l], nmove);
    for (int i = (0); i < (((int)(tomove).size())); ++i)
      ans.push_back(Move(r, l, tomove[i]));
    remove(have[r], tomove);
    have[l] = merge(have[l], tomove);
  }
}
void run() {
  scanf("%d%d", &n, &nkind);
  for (int i = (0); i < (n); ++i) {
    int cnt;
    scanf("%d", &cnt);
    have[i] = vector<int>(cnt);
    for (int j = (0); j < (cnt); ++j) scanf("%d", &have[i][j]), --have[i][j];
  }
  solve();
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i)
    printf("%d %d %d\n", ans[i].from + 1, ans[i].to + 1, ans[i].kind + 1);
}
int main() {
  run();
  return 0;
}
