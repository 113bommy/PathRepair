#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max = 0;
  cin >> n;
  int arr[1000000] = {0};
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr[temp] = temp;
  }
  for (int i = 0; i < 1000000; i++) {
    if (arr[i] == 0 && i > 0) arr[i] = arr[i - 1];
  }
  for (int i = 1; i < 1000000; i++) {
    if (arr[i] == i) {
      for (int j = 2 * i - 1; j < 1000000; j += i) {
        if (max <= arr[j] % i) {
          max = arr[j] % i;
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}
