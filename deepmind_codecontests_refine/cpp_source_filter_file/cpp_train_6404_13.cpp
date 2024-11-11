#include <bits/stdc++.h>
using namespace std;
int main() {
  char num1[101], num2[101];
  cin >> num1;
  cin >> num2;
  int i = 0, n;
  while (num1[i] != '\0') {
    i++;
  }
  n = i;
  char output[n];
  for (i = 0; i < n; i++) {
    if (num1[i] != num2[i]) {
      output[i] = '1';
    } else {
      output[i] = '0';
    }
  }
  for (i = 0; i < n; i++) {
    cout << output[i] << endl;
  }
  cout << endl;
  return 0;
}
