#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int len = 40;
  vector<string> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    len = min(len, (int)arr[i].length());
  }
  bool f = true;
  int j = 0;
  for (j = 0; j < len && f; ++j)
    for (int i = 1; i < arr.size(); ++i)
      if (arr[i][j] != arr[i - 1][j]) {
        f = 0;
        break;
      }
  if (j == len && !f) --j;
  cout << j;
  return 0;
}
