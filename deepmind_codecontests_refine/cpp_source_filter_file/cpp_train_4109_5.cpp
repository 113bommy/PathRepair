#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int a, b, c;
  int arr[8];
  cin >> a >> b >> c;
  arr[0] = a * b * c;
  arr[1] = a + b + c;
  arr[2] = a + (b * c);
  arr[3] = a * (b + c);
  arr[4] = (a + b) * c;
  arr[5] = (a * b) + c;
  sort(arr, arr + 8, greater<int>());
  cout << arr[0];
  return 0;
}
