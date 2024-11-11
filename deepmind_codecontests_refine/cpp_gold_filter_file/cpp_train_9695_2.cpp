#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  int arr[s], i;
  for (i = 0; i < s; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + s);
  int ans = 0;
  for (i = 0; i < s; i = i + 2) ans += arr[i + 1] - arr[i];
  cout << ans << endl;
  return 0;
}
