#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[100], temp, SIZE;
  cin >> SIZE;
  for (int i = 0; i < SIZE; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i];
  }
}
