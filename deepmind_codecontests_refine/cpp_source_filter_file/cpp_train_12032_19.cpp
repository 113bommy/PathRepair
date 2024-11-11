#include <bits/stdc++.h>
using namespace std;
void print(int c) {
  if (c < 10) {
    printf("%d", c);
  } else {
    putchar('a' + (c - 10));
  }
}
vector<int> vdiff(vector<int> v, int p) {
  v[p]--;
  return v;
}
map<pair<int, vector<int>>, long long> mp;
long long getdp(int ndig, vector<int> lim) {
  if (!is_sorted(lim.begin(), lim.end())) {
    sort(lim.begin(), lim.end());
  }
  if (mp.count({ndig, lim})) {
    return mp[{ndig, lim}];
  }
  long long &ref = mp[{ndig, lim}];
  if (ndig == 0) {
    return ref = 1;
  }
  for (int i = 0; i < 16; i++) {
    if (lim[i]) {
      vector<int> nlim = vdiff(lim, i);
      ref += getdp(ndig - 1, nlim);
    }
  }
  return ref;
}
int K, T;
void go(int ndig, vector<int> lim, long long kval) {
  if (ndig == 0) {
    return;
  }
  for (int i = 0; i < 16; i++) {
    if (lim[i] == 0) {
      continue;
    }
    vector<int> nlim = vdiff(lim, i);
    long long nways = getdp(ndig - 1, nlim);
    if (kval <= nways) {
      print(i);
      go(ndig - 1, nlim, kval);
      return;
    } else {
      kval -= nways;
    }
  }
}
int main() {
  scanf("%d %d", &K, &T);
  int ndig = 1;
  while (true) {
    vector<int> lim = vdiff(vector<int>(16, T), 0);
    long long nways = 15 * getdp(ndig - 1, lim);
    if (nways <= K) {
      K -= nways;
      ndig++;
    } else {
      break;
    }
  }
  vector<int> vdlim(16, T);
  long long pways = getdp(ndig - 1, vdiff(vdlim, 0));
  for (int i = 1; i < 16; i++) {
    if (K <= pways) {
      print(i);
      go(ndig - 1, vdiff(vdlim, i), K);
      break;
    }
    K -= pways;
  }
  puts("");
}
