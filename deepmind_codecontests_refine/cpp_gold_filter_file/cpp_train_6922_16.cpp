#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2;
  cin >> n1 >> n2;
  int k, m;
  cin >> k >> m;
  int A[n1];
  int B[n2];
  for (int i = 0; i < n1; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> B[i];
  }
  if (A[k - 1] < B[n2 - m]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
