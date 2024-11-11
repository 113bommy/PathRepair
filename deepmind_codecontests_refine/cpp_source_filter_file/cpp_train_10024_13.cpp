#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int Min = INT_MAX;
  int Max = INT_MIN;
  int Min_index;
  int Max_index;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= Min) {
      Min = arr[i];
      Min_index = i;
    }
    if (arr[i] >= Max) {
      Max = arr[i];
      Max_index = i;
    }
  }
  int counter = 0;
  while (Max_index != 0) {
    int temp = arr[Max_index];
    arr[Max_index] = arr[Max_index - 1];
    arr[Max_index - 1] = temp;
    Max_index = Max_index - 1;
    counter++;
  }
  for (int i = 0; i < n; i++) {
    if (Min == arr[i]) {
      Min_index = i;
    }
  }
  while (Min_index != (n - 1)) {
    int temp = arr[Min_index];
    arr[Min_index] = arr[Min_index + 1];
    arr[Min_index + 1] = temp;
    Min_index = Min_index + 1;
    counter++;
  }
  cout << counter << endl;
}
