#include <bits/stdc++.h>
using namespace std;
int main() {
  int number;
  cin >> number;
  int arr[number][2];
  for (int i = 0; i < number; i++) {
    cin >> arr[i][0];
    arr[i][1] = i + 1;
  }
  for (int i = 0; i < number; i++) {
    for (int j = i; j < number; j++) {
      if (arr[i][0] > arr[j][0]) {
        swap(arr[i][0], arr[j][0]);
        swap(arr[i][1], arr[j][1]);
      }
    }
  }
  for (int i = 0; i < number / 2; i++) {
    cout << arr[i][1] << " " << arr[number - i - 1][1] << endl;
  }
  return 0;
}
