#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T, n, i, j;
  long long S_0, S_1, F_0, F_1, count;
  cin >> T;
  while (T--) {
    cin >> n;
    string A[n];
    for (i = 0; i < n; i++) {
      cin >> A[i];
    }
    S_0 = 0;
    S_1 = 0;
    F_0 = 0;
    F_1 = 0;
    if (A[0][1] == '0')
      S_0 += 1;
    else
      S_1 += 1;
    if (A[1][0] == '0')
      S_0 += 1;
    else
      S_1 += 1;
    if (A[n - 2][n - 1] == '0')
      F_0 += 1;
    else
      F_1 += 1;
    if (A[n - 1][n - 2] == '0')
      F_0 += 1;
    else
      F_1 += 1;
    count = 0;
    vector<long long> X;
    vector<long long> Y;
    if (S_0 == 2) {
      if (A[n - 1][n - 2] == '0') {
        X.push_back(n - 1);
        Y.push_back(n - 2);
        count += 1;
      }
      if (A[n - 2][n - 1] == '0') {
        X.push_back(n - 2);
        Y.push_back(n - 1);
        count += 1;
      }
    } else if (S_1 == 2) {
      if (A[n - 1][n - 2] == '1') {
        X.push_back(n - 1);
        Y.push_back(n - 2);
        count += 1;
      }
      if (A[n - 2][n - 1] == '1') {
        X.push_back(n - 2);
        Y.push_back(n - 1);
        count += 1;
      }
    } else if (F_1 == 2) {
      if (A[0][1] == '1') {
        X.push_back(0);
        Y.push_back(1);
        count += 1;
      }
      if (A[1][0] == '1') {
        X.push_back(1);
        Y.push_back(0);
        count += 1;
      }
    } else if (F_0 == 2) {
      if (A[0][1] == '0') {
        X.push_back(0);
        Y.push_back(1);
        count += 1;
      }
      if (A[1][0] == '0') {
        X.push_back(1);
        Y.push_back(0);
        count += 1;
      }
    } else if ((S_0 == 1 || S_1 == 1) && (F_0 == 1 || F_1 == 1)) {
      if (A[0][1] == '1') {
        count += 1;
        X.push_back(0);
        Y.push_back(1);
      }
      if (A[1][0] == '1') {
        count += 1;
        X.push_back(1);
        Y.push_back(0);
      }
      if (A[n - 2][n - 1] == '0') {
        count += 1;
        X.push_back(n - 2);
        Y.push_back(n - 1);
      }
      if (A[n - 1][n - 2] == '0') {
        count += 1;
        X.push_back(n - 1);
        Y.push_back(n - 2);
      }
    }
    cout << count << "\n";
    for (i = 0; i < X.size(); i++) {
      cout << (X[i] + 1) << " " << (Y[i] + 1) << "\n";
    }
  }
  return 0;
}
