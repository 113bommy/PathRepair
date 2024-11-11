#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  for (long long int tc = 1; tc <= tt; tc++) {
    long long int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] == arr[2] or arr[1] == arr[2]) {
      cout << "YES";
      cout << '\n';
      cout << arr[0] << " " << arr[1] << " " << arr[2];
    } else
      cout << "NO";
    cout << '\n';
  }
  return 0;
}
