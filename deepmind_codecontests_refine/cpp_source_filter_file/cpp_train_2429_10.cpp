#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  string str, s;
  cin >> n >> str;
  long long int ar1[n], ar2[n];
  for (int i = 0; i < n; i++) {
    s = str.at(i);
    istringstream(s) >> ar1[i];
    s = str.at(i + n);
    istringstream(s) >> ar2[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (ar1[j] > ar1[j + 1]) {
        ar1[j + 1] += ar1[j];
        ar1[j] = ar1[j + 1] - ar1[j];
        ar1[j + 1] -= ar1[j];
      }
      if (ar2[j] > ar2[j + 1]) {
        ar2[j + 1] += ar2[j];
        ar2[j] = ar2[j + 1] - ar2[j];
        ar2[j + 1] -= ar2[j];
      }
    }
  }
  int i = 0;
  for (i = 0; i < n; i++) {
    if (ar1[i] < ar2[i]) {
      k++;
      break;
    }
  }
  for (i = 0; i < n; i++) {
    if (ar1[i] > ar2[i]) {
      k++;
      break;
    }
  }
  if (k == 1)
    cout << "YES";
  else
    cout << "NO";
}
