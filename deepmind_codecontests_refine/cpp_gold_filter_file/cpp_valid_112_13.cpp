#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m;
    int arr[5];
    cin >> arr[1] >> arr[2] >> arr[3] >> m;
    sort(arr + 1, arr + 3 + 1);
    if ((arr[3] - arr[2] - arr[1] - 1) > m)
      cout << "NO" << endl;
    else if ((arr[3] + arr[2] + arr[1] - 3) < m)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
