#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000;
long long prost1 = 36028797018963913;
long long prost2 = 35184372088777;
long long scal_prod(pair<long long, long long> l,
                    pair<long long, long long> r) {
  return l.first * r.first + l.second * r.second;
}
long long vec_prod(pair<long long, long long> l, pair<long long, long long> r) {
  return l.first * r.second - l.second * r.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long kol_vo;
  cin >> kol_vo;
  vector<long long> v(kol_vo);
  for (long long c = 0; c < kol_vo; c++) cin >> v[c];
  vector<long long> dop(kol_vo);
  for (long long c = 0; c < kol_vo; c++) {
    dop[c] = __builtin_popcountll(v[c]);
  }
  pair<long long, long long> answ;
  answ.first = 1;
  answ.second = 0;
  long long bit = 0, an = 0;
  for (long long c = 0; c < kol_vo; c++) {
    bit += dop[c];
    if (bit % 2) {
      an += answ.second;
      answ.second++;
    } else {
      an += answ.first;
      answ.first++;
    }
  }
  long long mmax = -1, all;
  for (long long c = 0; c < kol_vo; c++) {
    mmax = -1, all = 0;
    for (long long i = c; i < c + 63 && i < kol_vo; i++) {
      mmax = max(mmax, dop[i]);
      all += dop[i];
      if (mmax * 2 > all && all % 2 == 0) an--;
    }
  }
  cout << an;
  return 0;
}
