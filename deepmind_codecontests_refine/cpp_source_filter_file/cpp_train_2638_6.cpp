#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int sz = 400400;
pair<int, int> HM[sz];
pair<int, int> LH[sz];
int BIT[sz], h, m, n, cur, LL, HH;
int clen;
map<int, pair<int, int> > hm;
void go(int v) {
  if (!HM[v].first) {
    clen++;
    HM[v].first = ++cur;
    LH[v].first = LL;
    v += m;
    if (v > h) v -= h;
    go(v);
  }
}
int bitsum(int S) {
  int ans = 0;
  while (S) {
    ans += BIT[S];
    S -= (S & (-S));
  }
  return ans;
}
int sum(int l, int r) { return bitsum(r) - bitsum(l - 1); }
void add(int idx, int ad) {
  while (idx <= (2 * h)) {
    BIT[idx] += ad;
    idx += (idx & (-idx));
  }
}
int main() {
  char ch;
  int ID, id, hv, pid, nid, res = 0;
  cin >> h >> m >> n;
  for (int i = 1; i <= h; i++) {
    if (!HM[i].first) {
      clen = 0;
      LL = cur + 1;
      go(i);
      for (int j = 1, ind = i; j <= clen; j++) {
        HM[ind].second = cur + j;
        LH[ind].second = cur + clen;
        ind += m;
        if (ind > h) ind -= h;
      }
      cur += clen;
    }
  }
  for (int it = 1; it <= n; it++) {
    cin >> ch;
    if (ch == '+') {
      cin >> ID >> hv;
      hv++;
      id = HM[hv].first;
      pid = id;
      for (int i = 20; i >= 0; i--) {
        if ((id + (1 << i) - 1) <= (2 * h) &&
            sum(id, id + (1 << i) - 1) == (1 << i))
          id += (1 << i);
      }
      res += (id - pid);
      add(id, 1);
      nid = HM[hv].second + (id - pid);
      if (nid > LH[hv].second) nid = (LH[hv].first + nid - LH[hv].second - 1);
      add(nid, 1);
      hm[ID] = make_pair(id, nid);
    } else {
      cin >> ID;
      id = hm[ID].first;
      add(id, -1);
      id = hm[ID].second;
      add(id, -1);
      hm[ID] = make_pair(0, 0);
    }
  }
  cout << res << endl;
  return 0;
}
