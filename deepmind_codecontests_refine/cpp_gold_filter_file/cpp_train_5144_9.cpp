#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int arr[x];
  for (int i = 0; i < x; i++) cin >> arr[i];
  sort(arr, arr + x);
  int sum = 0;
  int i = 0;
  while (arr[i] < 0 && i < y) {
    sum += arr[i];
    i++;
  }
  sum *= -1;
  cout << sum << endl;
  return 0;
}
