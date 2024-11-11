#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 1e6 + 10;
const long long md = 1e9 + 7;
const long long Inf = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  long long N;
  cin >> N;
  vector<long long> Vals(N);
  vector<long long> Masks(N);
  vector<long long> Len(N);
  long long Sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> Vals[i] >> Masks[i];
    long long t = 0;
    long long a = Masks[i];
    while (!(a & 1)) {
      a >>= 1;
      t++;
    }
    Len[i] = t;
    Sum += Vals[i];
  }
  if (Sum < 0) {
    for (int i = 0; i < N; i++) {
      Vals[i] = -Vals[i];
    }
    Sum = -Sum;
  }
  long long S = 0;
  for (int i = 62; i >= 0; i--) {
    long long t1 = 0;
    long long t2 = 0;
    for (int j = 0; j < N; j++) {
      if (Len[j] == i) {
        long long c = S & Masks[j];
        long long Cnt = 0;
        while (c) {
          Cnt += (c & 1);
          c >>= 1;
        }
        if (Cnt & 1)
          t1 += Vals[j];
        else
          t2 += Vals[j];
      }
    }
    if (t2 > t1) {
      S |= (1ll << i);
    }
  }
  cout << S << '\n';
  return 0;
}
