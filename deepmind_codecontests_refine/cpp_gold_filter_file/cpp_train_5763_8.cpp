#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int r, c;
  cin >> r >> c;
  vector<vector<long long> > m(r, vector<long long>(c));
  vector<long long> accr(r, 0);
  vector<long long> accc(c, 0);
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
      accr[i] += m[i][j];
      accc[j] += m[i][j];
    }
  long long minid = 1LL << 62;
  long long minjd = 1LL << 62;
  long long mini;
  long long minj;
  for (long long y = -1; y <= r; y++) {
    long long total = 0;
    for (long long i = 0; i < r; i++) {
      long long dist = (4LL * (y - i) + 2LL);
      dist *= dist;
      dist *= accr[i];
      total += dist;
    }
    if (total < minid) {
      minid = total;
      mini = y;
    }
  }
  for (long long x = -1; x <= c; x++) {
    long long total = 0;
    for (long long j = 0; j < c; j++) {
      long long dist = (4LL * (x - j) + 2LL);
      dist *= dist;
      dist *= accc[j];
      total += dist;
    }
    if (total < minjd) {
      minjd = total;
      minj = x;
    }
  }
  mini++;
  minj++;
  cout << (minid + minjd) << endl;
  cout << mini << " " << minj << endl;
  return 0;
}
