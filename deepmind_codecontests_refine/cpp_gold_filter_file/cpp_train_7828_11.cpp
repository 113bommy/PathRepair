#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a, num = 0, temp = 0;
  cin >> k;
  int arr[100] = {0};
  for (int i = 0; i < k; i++) {
    cin >> a;
    arr[a - 1]++;
    if (arr[a - 1] > 3) {
      num++;
      arr[a - 1] = arr[a - 1] % 4;
    }
  }
  for (int i = 0; i < 100; i++) {
    if (arr[i] > 1) temp++;
  }
  cout << num + (temp / 2);
  return 0;
}
