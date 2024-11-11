#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int arr[b];
  int count = 0;
  for (int x = 0; x < b; x++) {
    cin >> arr[x];
  }
  sort(arr, arr + b);
  if (arr[0] = 1 || arr[b - 1] == a) {
    count = 1;
  } else {
    for (int y = 1; y < b - 1; y++) {
      if (arr[y] - arr[y - 1] == 1 && arr[y + 1] - arr[y] == 1) {
        count = 1;
        break;
      } else {
        count = 0;
      }
    }
  }
  if (count == 1) {
    cout << "NO";
  }
  if (count == 0) {
    cout << "YES";
  }
}
