#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[200000], arr1[200000] = {}, counter = 1, counter2 = 0, index;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (counter2 == 0 && arr[i] == 0) {
      index = i;
      counter2++;
      arr1[i] = 0;
    }
  }
  for (int i = index - 1; i >= 0; i--) {
    arr1[i] = counter2;
    counter2++;
  }
  counter = 1;
  for (int i = index + 1; i < n; i++) {
    if (arr[i] != 0) {
      arr1[i] = counter;
      counter++;
    } else {
      counter = 1;
    }
  }
  counter = arr1[n - 1];
  for (int i = n - 1; i > index; i--) {
    if (arr[i] == 0) {
      counter = 1;
    } else {
      if (arr1[i] > counter) {
        arr1[i] = counter;
        counter++;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << arr1[i] << " ";
  cout << endl;
  return 0;
}
