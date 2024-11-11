#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, a, t = 0, maxm = 0, tempmax = 0, k;
  cin >> n >> k;
  vector<long long int> A;
  for (i = 0; i < n; i++) {
    cin >> a;
    A.push_back(a);
    if (maxm < a) maxm = a;
  }
  if (k >= n - 1)
    cout << maxm << endl;
  else {
    tempmax = A[0];
    for (i = 1; i < n; i++) {
      if (A[i] == maxm || tempmax == maxm) {
        cout << maxm << endl;
        break;
      } else {
        if (tempmax > A[i]) {
          t++;
          if (t == k) {
            cout << tempmax << endl;
            break;
          }
        } else {
          tempmax = A[i];
          t = 1;
        }
      }
    }
  }
  return 0;
}
