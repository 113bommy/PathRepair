#include <bits/stdc++.h>
using namespace std;
int main() {
  int num = 0;
  cin >> num;
  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    cin >> arr[i];
  }
  int max = arr[0];
  int index;
  for (int i = 0; i < num; ++i) {
    if (arr[i] > max) {
      max = arr[i];
      index = i;
    }
  }
  sort(&arr[0], &arr[num], greater<int>());
  cout << index + 1 << " " << arr[1];
  return 0;
}
