#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, sum = 0;
  cin >> n;
  char arr[100][100];
  int arr2[100] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'C') {
        arr2[j]++;
        c++;
      }
    }
    for (int i = c - 1; i >= 1; i--) {
      sum += i;
    }
    c = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = arr2[i] - 1; j >= 1; j--) {
      sum += j;
    }
  }
  cout << sum;
  return 0;
}
