#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m = 0, c = -1;
  cin >> n;
  string str;
  int a[8] = {0};
  vector<int> arr[7];
  for (i = 0; i < 7; i++) arr[i].push_back(0);
  for (i = 0; i < n; i++) {
    cin >> k;
    cin >> str;
    if (str == "A")
      arr[0].push_back(k);
    else if (str == "B")
      arr[1].push_back(k);
    else if (str == "C")
      arr[2].push_back(k);
    else if (str == "AB" || str == "BA")
      arr[3].push_back(k);
    else if (str == "BC" || str == "CB")
      arr[4].push_back(k);
    else if (str == "AC" || str == "CA")
      arr[5].push_back(k);
    else
      arr[6].push_back(k);
  }
  for (i = 0; i < 7; i++) sort(arr[i].begin(), arr[i].end());
  for (i = 0; i < 7; i++) arr[i].push_back(0);
  if (arr[0][1] != 0 && arr[1][1] != 0 && arr[2][1] != 0)
    a[0] = arr[0][1] + arr[1][1] + arr[2][1];
  if (arr[0][1] != 0 && arr[4][1] != 0) a[1] = arr[0][1] + arr[4][1];
  if (arr[1][1] != 0 && arr[5][1] != 0) a[2] = arr[1][1] + arr[5][1];
  if (arr[2][1] != 0 && arr[3][1] != 0) a[3] = arr[2][1] + arr[3][1];
  if (arr[6][1] != 0) a[4] = arr[6][1];
  if (arr[3][1] != 0 && arr[4][1] != 0) a[5] = arr[4][1] + arr[3][1];
  if (arr[4][1] != 0 && arr[5][1] != 0) a[6] = arr[4][1] + arr[5][1];
  if (arr[5][1] != 0 && arr[3][1] != 0) a[7] = arr[5][1] + arr[3][1];
  sort(a, a + 8);
  for (i = 0; i < 8; i++) {
    if (a[i] != 0) {
      c = a[i];
      break;
    }
  }
  cout << c;
  return 0;
}
