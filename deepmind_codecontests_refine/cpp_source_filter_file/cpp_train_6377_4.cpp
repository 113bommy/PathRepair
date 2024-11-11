#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int seg[N * 4];
map<char, bool> vw;
int laz[N * 4];
void spl(int v) {
  laz[v * 2] += laz[v];
  laz[v * 2 + 1] += laz[v];
  seg[v * 2] += laz[v];
  seg[v * 2 + 1] += laz[v];
  laz[v] = 0;
}
void add(int l, int r, int val, int v = 1, int s = 1, int e = N) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    laz[v] += val;
    seg[v] += val;
    return;
  }
  spl(v);
  add(l, r, val, v * 2, s, ((s + e) / 2));
  add(l, r, val, v * 2 + 1, ((s + e) / 2), e);
  seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}
int get(int l, int r, int v = 1, int s = 1, int e = N) {
  if (r <= s || e <= l) return -1e9;
  if (l <= s && e <= r) return seg[v];
  spl(v);
  return max(get(l, r, v * 2, s, ((s + e) / 2)),
             get(l, r, v * 2 + 1, ((s + e) / 2), e));
}
int main() {
  vw['A'] = 1;
  vw['a'] = 1;
  vw['E'] = 1;
  vw['e'] = 1;
  vw['I'] = 1;
  vw['i'] = 1;
  vw['O'] = 1;
  vw['o'] = 1;
  vw['U'] = 1;
  vw['u'] = 1;
  string s;
  cin >> s;
  int mxd = 0;
  for (int i = 1; i <= s.size(); i++) {
    if (vw[s[i - 1]])
      add(1, i + 1, -1);
    else
      add(1, i + 1, 2);
    int l = 0, r = i + 1;
    while (r - l > 1) {
      int md = (r + l) / 2;
      if (get(1, md) >= 0)
        r = md;
      else
        l = md;
    }
    if (r == i + 1) continue;
    mxd = max(mxd, i - l + 1);
  }
  if (mxd == 0) {
    cout << "No solution";
    return 0;
  }
  cout << mxd << endl;
  int sm = 0, res = 0;
  for (int i = 1; i <= s.size(); i++) {
    if (vw[s[i - 1]])
      sm--;
    else
      sm += 2;
    if (i > mxd) {
      if (vw[s[i - mxd - 1]])
        sm++;
      else
        sm -= 2;
    }
    if (i >= mxd && sm >= 0) res++;
  }
  cout << res;
  return 0;
}
