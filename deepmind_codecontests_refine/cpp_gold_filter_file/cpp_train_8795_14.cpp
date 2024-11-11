#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int limak = arr[0];
  sort(arr + 1, arr + n);
  int hasil = 0;
  while (limak <= arr[n - 1]) {
    limak++;
    hasil++;
    arr[n - 1]--;
    sort(arr + 1, arr + n);
  }
  cout << hasil << endl;
  return 0;
}
