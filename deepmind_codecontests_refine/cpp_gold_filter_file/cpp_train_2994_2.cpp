#include <bits/stdc++.h>
using namespace std;
int compare(string S, string y) {
  if (S.size() != y.size())
    return 0;
  else {
    int i;
    for (i = 0; i < S.size(); i++) {
      if (S[i] != y[i]) return 0;
    }
  }
  return 1;
}
int main() {
  long int temp = INT_MAX;
  long int min = INT_MAX;
  long int n;
  cin >> n;
  long int A[n];
  long int B[n];
  int i, j, k;
  for (i = 0; i < n; i++) cin >> A[i];
  for (i = 0; i < n; i++) cin >> B[i];
  long long int ans[n];
  int flag = 0;
  for (i = 1; i < n; i++) {
    ans[i] = B[i];
    temp = INT_MAX;
    for (j = 0; j < i; j++) {
      if (B[j] < temp && A[j] < A[i]) {
        temp = B[j];
        flag = 1;
      }
    }
    ans[i] = ans[i] + temp;
  }
  if (flag == 0) {
    cout << "-1\n";
    return 0;
  }
  flag = 0;
  for (i = 1; i < n - 1; i++) {
    temp = INT_MAX;
    for (j = i + 1; j < n; j++) {
      if (B[j] < temp && A[j] > A[i]) {
        flag = 1;
        temp = B[j];
      }
    }
    ans[i] = ans[i] + temp;
    if (ans[i] < min) min = ans[i];
  }
  if (flag == 0) {
    cout << "-1\n";
    return 0;
  }
  cout << min << endl;
  return 0;
}
