#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[10001];
  int i = 1;
  int j = 1;
  while (i < 10001) {
    if (j < 10) {
      arr[i] = j;
      i++;
    }
    if (j >= 10 && j < 100) {
      arr[i] = j / 10;
      arr[i + 1] = j % 10;
      i += 2;
    }
    if (j >= 100 && j < 1000) {
      arr[i] = j / 100;
      arr[i + 1] = j / 10 - arr[i] * 10;
      arr[i + 2] = j % 10;
      i += 3;
    }
    if (j >= 1000) {
      arr[i] = j / 1000;
      arr[i + 1] = j / 100 - arr[i] * 10;
      arr[i + 2] = j / 10 - arr[i + 1] * 10 - arr[i] * 100;
      arr[i + 3] = j % 10;
      i += 4;
    }
    j++;
  }
  int k;
  cin >> k;
  cout << arr[k];
  return 0;
}
