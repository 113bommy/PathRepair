#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char arr[n][n];
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      arr[j][i] = '.';
    }
  }
  int count = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (j > 0 && arr[j - 1][i] == 'c') {
        continue;
      }
      if (i > 0 && arr[j][i - 1] == 'c') {
        continue;
      }
      if (j < n - 1 && arr[j + 1][i] == 'c') {
        continue;
      }
      if (i < n - 1 && arr[j][i + 1] == 'c') {
        continue;
      }
      count++;
      arr[j][i] = 'c';
    }
  }
  cout << count << endl;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      cout << arr[j][i];
    }
    cout << endl;
  }
}
