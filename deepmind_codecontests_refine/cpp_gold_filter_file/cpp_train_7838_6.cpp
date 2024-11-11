#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[12], k, c = 0, a = 0;
  cin >> k;
  for (int i = 0; i < 12; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + 12);
  for (int i = 11; i >= 0; i--) {
    if (c < k) {
      c += arr[i];
      a++;
    }
  }
  if (c < k)
    cout << "-1";
  else
    cout << a;
  return 0;
}
