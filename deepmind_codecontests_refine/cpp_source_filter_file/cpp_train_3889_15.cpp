#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i < j); }
istream &in = cin;
int n, m;
long long N[1001], M[1001];
int main() {
  memset(N, 0, sizeof(N));
  memset(M, 0, sizeof(M));
  in >> n >> m;
  for (int i = (0); i < (n); ++i) {
    long long sum = 0;
    for (int j = (0); j < (m); ++j) {
      long long tmp;
      in >> tmp;
      M[j] += tmp;
      sum += tmp;
    }
    N[i] = sum;
  }
  int idxM = -1;
  long long mM = LLONG_MAX;
  for (int i = 0; i <= m; ++i) {
    long long sum = 0;
    for (int j = 0; j < m; ++j)
      sum += M[j] * (j * 4 + 2 - i * 4) * (j * 4 + 2 - i * 4);
    if (sum < mM) {
      mM = sum;
      idxM = i;
    }
  }
  int idxN = -1;
  int mN = LLONG_MAX;
  for (int i = 0; i <= n; ++i) {
    long long sum = 0;
    for (int j = 0; j < n; ++j)
      sum += N[j] * (j * 4 + 2 - i * 4) * (j * 4 + 2 - i * 4);
    if (sum < mM) {
      mN = sum;
      idxN = i;
    }
  }
  cout << mN + mM << endl;
  cout << idxN << " " << idxM << endl;
  return 0;
}
