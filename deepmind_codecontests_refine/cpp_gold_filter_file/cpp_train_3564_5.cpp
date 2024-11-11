#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int fst1 = LLONG_MAX;
    long long int fstm1 = LLONG_MAX;
    long long int n;
    cin >> n;
    long long int fst[n];
    long long int sec[n];
    for (long long int i = 0; i < n; i++) cin >> fst[i];
    for (long long int i = 0; i < n; i++) cin >> sec[i];
    for (long long int i = 0; i < n; i++)
      if (fst[i] == 1) {
        fst1 = i;
        break;
      }
    for (long long int i = 0; i < n; i++)
      if (fst[i] == -1) {
        fstm1 = i;
        break;
      }
    if (fst[0] != sec[0]) {
      cout << "NO" << endl;
      continue;
    }
    for (long long int i = 1; i < n; i++) {
      if (sec[i] > fst[i]) {
        if (i <= fst1) goto ok;
      }
      if (sec[i] < fst[i]) {
        if (i <= fstm1) goto ok;
      }
    }
    cout << "YES" << endl;
    continue;
  ok:
    cout << "NO" << endl;
  }
}
