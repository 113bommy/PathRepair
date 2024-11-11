#include <bits/stdc++.h>
using namespace std;
long long q, n, R[50002][5];
bool Sortiraj(long long u, long long v) {
  long long br = 0;
  for (long long j = 1; j <= 5; j++) {
    br += (R[u][j] < R[v][j]);
  }
  return (br >= 3);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> q;
  while (q--) {
    cin >> n;
    vector<long long> A;
    for (long long i = 1; i <= n; i++) {
      A.push_back(i);
      for (long long j = 1; j <= 5; j++) {
        cin >> R[i][j];
      }
    }
    sort(A.begin(), A.end(), Sortiraj);
    long long k = A.front(), broj = 0, br = 0;
    for (long long i = 1; i <= n; i++) {
      if (k != i) {
        br = 0;
        for (long long j = 1; j <= 5; j++) {
          br += (R[k][j] < R[i][j]);
        }
        if (br < 3) {
          break;
        }
        broj++;
      }
    }
    if (broj != n - 1) {
      cout << "-1\n";
    } else {
      cout << k << "\n";
    }
    A.clear();
  }
  return 0;
}
