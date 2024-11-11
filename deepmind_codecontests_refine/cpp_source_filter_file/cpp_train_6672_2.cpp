#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n][2];
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  long long int x = max(arr[0][0], arr[0][1]);
  vector<int> v1;
  int fail = 0;
  for (int i = 1; i < n; i++) {
    long long int y = max(arr[i][0], arr[i][1]);
    long long int k = min(arr[i][0], arr[i][1]);
    if (y <= x) {
      v1.push_back(y);
      x = y;
    } else if (k <= x) {
      v1.push_back(k);
      x = y;
    } else {
      fail = 1;
      break;
    }
  }
  if (fail == 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
