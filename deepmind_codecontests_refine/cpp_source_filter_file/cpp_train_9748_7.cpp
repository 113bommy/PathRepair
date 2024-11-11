#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, q, i, j, a[200005], b[200005];
long long mi[800005], tag[800005], res[200005];
vector<pair<int, int> > v[200005];
multiset<long long> s;
void pushup(int x) { mi[x] = min(mi[x + x], mi[x + x + 1]); }
void build(int x, int l, int r) {
  if (l == r) {
    mi[x] = b[l];
    return;
  }
  int mid = (l + r) / 2;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  pushup(x);
}
void upd(int x, int c) {
  mi[x] += c;
  tag[x] += c;
}
void pushdo(int x) {
  if (tag[x]) {
    upd(x + x, tag[x]);
    upd(x + x + 1, tag[x]);
    tag[x] = 0;
  }
}
void update(int x, int l, int r, int ql, int qr, int c) {
  if (ql <= l && r <= qr) {
    upd(x, c);
    return;
  }
  int mid = (l + r) / 2;
  pushdo(x);
  if (ql <= mid) update(x + x, l, mid, ql, qr, c);
  if (qr > mid) update(x + x + 1, mid + 1, r, ql, qr, c);
  pushup(x);
}
int main() {
  read(n);
  read(m);
  read(q);
  for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
    read(a[i]);
    read(b[i + 1]);
  }
  build(1, 1, n);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    int x, y, z;
    read(x);
    read(y);
    read(z);
    v[x].push_back(make_pair(y, z));
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    for (__typeof((v[i]).begin()) it = (v[i]).begin(); it != (v[i]).end();
         it++) {
      update(1, 1, n, 1, it->first, it->second);
    }
    res[i] = mi[1];
    s.insert(res[i] + a[i]);
  }
  printf("%lld\n", *s.begin());
  while (q--) {
    int x, y;
    read(x);
    read(y);
    s.erase(s.find(a[x] + res[x]));
    a[x] = y;
    s.insert(a[x] + res[x]);
    printf("%lld\n", *s.begin());
  }
  return 0;
}
