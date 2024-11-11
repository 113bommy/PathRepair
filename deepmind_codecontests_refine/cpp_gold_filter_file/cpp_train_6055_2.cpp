#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int check = 0;
  for (int i = 0; i < n; i++)
    if (i && arr[i] % 2 != arr[i - 1] % 2) {
      check = 1;
      break;
    }
  if (check) sort(arr, arr + n);
  for (int i : arr) cout << i << " ";
}
