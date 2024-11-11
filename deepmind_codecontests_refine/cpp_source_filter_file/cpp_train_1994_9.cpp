#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int temp[3] = {-1, 0, 0}, h = 1;
  int min = arr[0], max = arr[n - 1];
  for (int i = 1; i < n - 1; i++) {
    if (h == 3) {
      break;
    }
    if (arr[i] > min && arr[i] < max && arr[i] > temp[i]) {
      temp[h] = arr[i];
      h++;
    }
  }
  if (temp[2] > 0)
    cout << -1;
  else if (temp[1] == 0) {
    if ((min + max) % 2 == 1)
      cout << max - min;
    else
      cout << max - (max + min) / 2;
  } else if (max - temp[1] == temp[1] - min)
    cout << max - temp[1];
  else
    cout << -1;
  return 0;
}
