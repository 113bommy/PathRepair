#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxi = 1005;
int arr[maxi];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (n >= 2)
    cout << arr[1];
  else
    cout << arr[0];
}
