#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  int k;
  vector<vector<int> > A;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    vector<int> X;
    for (int j = 0; j < m; j++) {
      int l;
      cin >> l;
      X.push_back(l);
    }
    A.push_back(X);
  }
  int totalSum = 0;
  int changes = 0;
  for (int j = 0; j < m; j++) {
    int maxSum = 0;
    vector<int> maxI;
    maxI.push_back(0);
    for (int i = 0; i < n - 1; i++) {
      if (A[i][j] == 1) {
        int sum = 0;
        for (int z = i; z < min(i + k, n); z++) {
          sum += A[z][j];
        }
        if (sum > maxSum) {
          maxSum = sum;
          for (int elem = 0; elem < maxI.size(); elem++) {
            maxI[elem] = i;
          }
        } else if (sum == maxSum) {
          maxI.push_back(i);
        }
      }
    }
    int minimumChanges = 10000000;
    for (auto elem : maxI) {
      int toChange = 0;
      for (int i = 0; i < elem; i++) {
        if (A[i][j] == 1) {
          toChange++;
        }
      }
      if (toChange < minimumChanges) {
        minimumChanges = toChange;
      }
    }
    changes += minimumChanges;
    totalSum += maxSum;
  }
  cout << totalSum << " " << changes;
  return 0;
}
