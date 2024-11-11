#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m;
  vector<pair<int, int> > A(m);
  for (int i = 0; i < m; ++i) {
    cin >> A[i].first >> A[i].second;
  }
  cin >> n;
  vector<pair<int, int> > B(n);
  for (int i = 0; i < n; ++i) {
    cin >> B[i].first >> B[i].second;
  }
  int CsMAx, CfMin, PsMAx, PfMin;
  CsMAx = A[0].first;
  CfMin = A[0].second;
  PsMAx = B[0].first;
  PfMin = B[0].second;
  for (int i = 1; i < m; ++i) {
    if (A[i].first > CsMAx) CsMAx = A[i].first;
    if (A[i].second < CfMin) CfMin = A[i].second;
  }
  for (int i = 1; i < n; ++i) {
    if (B[i].first > CsMAx) PsMAx = B[i].first;
    if (B[i].second < CfMin) PfMin = B[i].second;
  }
  int one = (PsMAx - CfMin > 0) ? PsMAx - CfMin : 0;
  int two = (CsMAx - PfMin > 0) ? CsMAx - PfMin : 0;
  cout << max(one, two) << endl;
  return 0;
}
