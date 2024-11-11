#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
struct node {
  int sz;
  int knd[2];
  int len[2];
  int slen[2];
  int mx[2];
};
node operator+(const node& s, const node& t) {
  node res;
  res.sz = s.sz + t.sz;
  res.knd[0] = s.knd[0];
  res.knd[1] = t.knd[1];
  if (s.len[0] < s.sz || s.knd[0] != t.knd[0])
    res.len[0] = s.len[0];
  else
    res.len[0] = s.len[0] + t.len[0];
  if (t.len[1] < t.sz || s.knd[1] != t.knd[1])
    res.len[1] = t.len[1];
  else
    res.len[1] = s.len[1] + t.len[1];
  if (res.len[1] != res.sz) {
    if (s.len[0] == s.sz) {
      if (s.knd[0] == t.knd[0])
        res.slen[0] = t.slen[0];
      else
        res.slen[0] = t.len[0];
    } else {
      if (s.slen[0] + s.len[0] == s.sz && s.knd[0] != t.knd[0])
        res.slen[0] = s.slen[0] + t.len[0];
      else
        res.slen[0] = s.slen[0];
    }
    if (t.len[1] == t.sz) {
      if (s.knd[1] == t.knd[1])
        res.slen[1] = s.slen[1];
      else
        res.slen[1] = s.len[1];
    } else {
      if (t.slen[1] + t.len[1] == t.sz && t.knd[1] != s.knd[1])
        res.slen[1] = t.slen[1] + s.len[1];
      else
        res.slen[1] = t.slen[1];
    }
  } else
    res.slen[0] = res.slen[1] = 0;
  res.mx[0] = max(s.mx[0], t.mx[0]);
  res.mx[1] = max(s.mx[1], t.mx[1]);
  if (s.knd[1] == 1 && t.knd[0] == 0)
    res.mx[0] = max(res.mx[0], s.len[1] + t.len[0]);
  if (s.knd[1] == 0 && t.knd[0] == 1)
    res.mx[1] = max(res.mx[1], s.len[1] + t.len[0]);
  if (s.knd[1] == 1 && t.knd[0] == 1) {
    res.mx[0] = max(res.mx[0], s.len[1] + t.len[0] + t.slen[0]);
    res.mx[1] = max(res.mx[1], s.slen[1] + s.len[1] + t.len[0]);
  }
  if (s.knd[1] == 0 && t.knd[0] == 0) {
    res.mx[0] = max(res.mx[0], s.slen[1] + s.len[1] + t.len[0]);
    res.mx[1] = max(res.mx[1], s.len[1] + t.len[0] + t.slen[0]);
  }
  return res;
}
void operator~(node& s) {
  s.knd[0] ^= 1;
  s.knd[1] ^= 1;
  swap(s.mx[0], s.mx[1]);
}
const int N = 5e5 + 7;
node seg[N * 4];
bool laz[N * 4];
int n, q;
string str;
void prep(int v = 1, int s = 1, int e = n + 1) {
  if (e - s == 1) {
    seg[v].len[0] = seg[v].len[1] = 1;
    if (str[s - 1] == '>') seg[v].knd[0] = seg[v].knd[1] = 1;
    seg[v].mx[0] = seg[v].mx[1] = seg[v].sz = 1;
    return;
  }
  prep((v * 2), s, ((s + e) / 2));
  prep((v * 2 + 1), ((s + e) / 2), e);
  seg[v] = seg[(v * 2)] + seg[(v * 2 + 1)];
}
void spl(int v) {
  for (int u = (v * 2); u <= (v * 2 + 1); u++)
    if (laz[v]) {
      ~seg[u];
      laz[u] ^= 1;
    }
  laz[v] = 0;
}
void rev(int l, int r, int v = 1, int s = 1, int e = n + 1) {
  if (r <= s || e <= l) return;
  if (l <= s && e <= r) {
    ~seg[v];
    laz[v] ^= 1;
    return;
  }
  spl(v);
  rev(l, r, (v * 2), s, ((s + e) / 2));
  rev(l, r, (v * 2 + 1), ((s + e) / 2), e);
  seg[v] = seg[(v * 2)] + seg[(v * 2 + 1)];
}
node get(int l, int r, int v = 1, int s = 1, int e = n + 1) {
  if (r <= s || e <= l) return seg[0];
  if (l <= s && e <= r) {
    return seg[v];
  }
  spl(v);
  return get(l, r, (v * 2), s, ((s + e) / 2)) +
         get(l, r, (v * 2 + 1), ((s + e) / 2), e);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  cin >> str;
  prep();
  while (q--) {
    int l, r;
    cin >> l >> r;
    rev(l, r + 1);
    node s = get(l, r + 1);
    cout << s.mx[0] << ' ';
  }
}
