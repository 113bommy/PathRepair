#include <bits/stdc++.h>
using namespace std;
bool isSubSequence(char str1[], char str2[], int m, int n) {
  if (m == 0) return true;
  if (n == 0) return false;
  if (str1[m - 1] == str2[n - 1])
    return isSubSequence(str1, str2, m - 1, n - 1);
  return isSubSequence(str1, str2, m, n - 1);
}
bool isSubset(char arr1[], int m, char arr2[], int n) {
  map<char, int> frequency1;
  map<char, int> frequency2;
  for (int i = 0; i < n; i++) {
    frequency2[arr2[i]]++;
  }
  for (int i = 0; i < m; i++) {
    frequency1[arr1[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (frequency2[arr1[i]] >= frequency1[arr1[i]])
      continue;
    else {
      return false;
    }
  }
  return true;
}
int main() {
  int a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  int k1 = a[0][1] + a[0][2];
  int k2 = a[2][0] + a[2][1];
  int k3 = a[0][1] + a[2][1];
  a[1][1] = (k1 + k2 + k3) / 2 - k3;
  a[0][0] = (k1 + k2 + k3) / 2 - k1;
  a[2][2] = (k1 + k2 + k3) / 2 - k2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
