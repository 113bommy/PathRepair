#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18 + 10;
const long long M = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, v, sP = 0, sS = 0, st = 0, en;
    cin >> n;
    en = n - 1;
    vector<long long> A, S, P;
    for (__typeof(0) i = 0; i < n; i++) {
      cin >> v;
      sP += v;
      P.push_back(sP);
      A.push_back(v);
      if (sP <= 0) st = i;
    }
    for (__typeof(n - 1) i = n - 1; i > -1; i--) {
      sS += A[i];
      S.push_back(sS);
      if (sS <= 0) en = i;
    }
    if (st == 0 && en == n - 1)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
