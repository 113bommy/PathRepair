#include <bits/stdc++.h>
using namespace std;
int increaseValue(int d, int *value, int backValue);
int main() {
  int number, d, moves = 0;
  cin >> number >> d;
  int arr[number];
  for (int i = 0; i < number; i++) {
    cin >> arr[i];
    if (i > 0 && arr[i] <= arr[i - 1]) {
      moves += increaseValue(d, &arr[i], arr[i - 1]);
    }
  }
  cout << moves;
  return 0;
}
int increaseValue(int d, int *value, int backValue) {
  int moves = (backValue - *value) / d + 1;
  *value += d * moves;
  return moves;
}
