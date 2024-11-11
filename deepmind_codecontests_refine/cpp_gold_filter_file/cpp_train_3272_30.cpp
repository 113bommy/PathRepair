#include <bits/stdc++.h>
using namespace std;
void gravity(int x = 0) {
  int arr[101] = {0};
  for (int i = 0; i < x; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + x);
  for (int i = 0; i < x; i++) {
    cout << arr[i] << " ";
  }
}
int main() {
  int x;
  cin >> x;
  gravity(x);
  return 0;
}
