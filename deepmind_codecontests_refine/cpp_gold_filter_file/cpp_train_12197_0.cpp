#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long k;
  cin >> k;
  long long p = sqrt(k);
  while (1) {
    if (k % p == 0) break;
    p--;
  }
  long long q = k / p;
  vector<vector<char>> ans(p, vector<char>(q));
  if (p >= 5 && q >= 5) {
    for (long long i = 0; i < p; i++) {
      for (long long j = 0; j < q; j++) {
        if ((i + j) % 5 == 0)
          ans[i][j] = 'a';
        else if ((i + j) % 5 == 1)
          ans[i][j] = 'e';
        else if ((i + j) % 5 == 2)
          ans[i][j] = 'i';
        else if ((i + j) % 5 == 3)
          ans[i][j] = 'o';
        else if ((i + j) % 5 == 4)
          ans[i][j] = 'u';
        else
          ans[i][j] = 'x';
      }
    }
    for (long long i = 0; i < p; i++) {
      for (long long j = 0; j < q; j++) cout << ans[i][j];
    }
    cout << endl;
  } else
    cout << -1 << endl;
  return 0;
}
