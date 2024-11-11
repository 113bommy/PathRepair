#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  long long tar = 0;
  vector<long long> v;
  long long x, y;
  for (int i = 0; i < (int)n; ++i) {
    cin >> x >> y;
    v.push_back(x ^ y);
    tar ^= x;
  }
  long long bans = 1;
  int cr = 0;
  vector<long long> base(64);
  for (int j = 0; j < (int)64; ++j) {
    if (cr >= v.size()) break;
    for (int i = cr; i < (int)v.size(); ++i) {
      if ((v[i] >> j) & 1) {
        swap(v[cr], v[i]);
        break;
      }
    }
    if (((v[cr] >> j) & 1) == 0) continue;
    base[j] = v[cr];
    bans *= 2;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (i != cr && ((v[i] >> j) & 1)) v[i] ^= v[cr];
    }
    ++cr;
  }
  for (int j = 0; j < (int)64; ++j) {
    if ((tar >> j) & 1) {
      tar ^= base[j];
    }
  }
  if (tar == 0) {
    cout << bans - 1 << '/' << bans << '\n';
  } else {
    cout << "1/1" << '\n';
  }
}
