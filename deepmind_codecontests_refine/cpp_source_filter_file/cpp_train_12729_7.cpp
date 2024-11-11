#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  string B;
  string sum;
  cin >> A >> B >> sum;
  if (A.length() + B.length() != sum.length()) {
    cout << "NO";
    return 0;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(sum.begin(), sum.end());
  int i = 0, j = 0, k = 0;
  while (i < A.length() && j < B.length()) {
    if (A[i] < B[j]) {
      if (A[i] != sum[k]) {
        cout << "No";
        return 0;
      }
      i++;
      k++;
    } else {
      if (B[j] != sum[k]) {
        cout << "No";
        return 0;
      }
      j++;
      k++;
    }
  }
  while (i < A.length()) {
    if (A[i] != sum[k]) {
      cout << "No";
      return 0;
    }
    i++;
    k++;
  }
  while (j < B.length()) {
    if (B[j] != sum[k]) {
      cout << "No";
      return 0;
    }
    j++;
    k++;
  }
  cout << "YES";
  return 0;
}
