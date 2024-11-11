#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long arr[10];
  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr + 3);
  if (arr[2] < arr[1] + arr[0]) {
    cout << 0;
  } else {
    cout << arr[2] - (arr[1] + arr[0]) + 1;
  }
  return 0;
}
