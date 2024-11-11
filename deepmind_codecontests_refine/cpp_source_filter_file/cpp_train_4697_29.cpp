#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  for (int i = 0; i < 2; i++) {
    for (int j = i; j < 2; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  if (arr[0] < arr[1] + arr[2])
    cout << "0" << endl;
  else
    cout << arr[0] + 1 - (arr[1] + arr[2]) << endl;
  return 0;
}
