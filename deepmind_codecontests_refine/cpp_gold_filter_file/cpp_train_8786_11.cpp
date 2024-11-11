#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int x, y;
  cin >> x >> y;
  int result = 0;
  for (int i = 0; i < n; ++i) {
    int sumx = 0;
    int sumy = 0;
    for (int j = 0; j < i; ++j) sumx += arr[j];
    for (int j = i; j < n; ++j) sumy += arr[j];
    if (sumx >= x && sumx <= y && sumy >= x && sumy <= y) {
      result = i + 1;
      break;
    }
  }
  cout << result << endl;
  return 0;
}
