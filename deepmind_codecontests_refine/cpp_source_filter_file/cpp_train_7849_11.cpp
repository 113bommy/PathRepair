#include <bits/stdc++.h>
using namespace std;
int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
vector<int> v[(1 << 15) + 10];
int bi[20];
int k;
void rec(int num, int mask, int pos) {
  if (pos < 0) {
    v[mask].push_back(num);
    return;
  }
  rec(num, mask, pos - 1);
  while (1) {
    num *= prime[pos];
    if (num >= 2 * k * k) break;
    rec(num, mask + (1 << pos), pos - 1);
  }
  return;
}
int main() {
  cin >> k;
  for (int i = 2; i < 16; i++) {
    for (int j = 0; j < (1 << i); j++) v[i].clear();
    rec(1, 0, i - 1);
    int f = 0;
    vector<int> ret;
    for (int j = 0; j < (1 << i); j++) f += v[j].size();
    if (f < k) continue;
    f = k;
    memset(bi, 0, sizeof(bi));
    for (int j = (1 << i) - 1; j >= 0; j--) {
      int nex = min((int)v[j].size(), f);
      f -= nex;
      for (int l = 0; l < nex; l++) ret.push_back(v[j][l]);
      for (int l = 0; l < i; l++) {
        if ((j & (1 << l))) bi[l] += nex;
      }
    }
    f = 0;
    for (int j = 0; j < i; j++) {
      if (bi[j] < (k + 1) / 2) f = 1;
    }
    if (f > 0) continue;
    sort(ret.begin(), ret.end());
    for (int j = 0; j < k; j++) {
      cout << ret[j];
      if (j < k - 1)
        cout << ' ';
      else
        cout << endl;
    }
    break;
  }
}
