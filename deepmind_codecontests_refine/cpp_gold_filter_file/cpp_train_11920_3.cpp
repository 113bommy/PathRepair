#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> arr, arr2, arr3;
  int n, num;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num;
    arr.push_back(num);
  }
  arr2 = arr;
  arr3 = arr;
  sort(arr2.begin(), arr2.end());
  if (arr2 == arr) {
    cout << 0 << " " << 0;
    return 0;
  } else {
    int i = 0, j = n - 1;
    int res1 = i, res2 = j;
    while (arr3[i] == i + 1) {
      i++;
      res1 = i;
    }
    while (arr3[j] == j + 1) {
      j--;
      res2 = j;
    }
    while (i + 1 != arr3[i] && arr3[j] != j + 1 && j != i) {
      swap(arr3[i], arr3[j]);
      i++;
      j--;
    }
    if (arr3 == arr2)
      cout << res1 + 1 << " " << res2 + 1;
    else
      cout << 0 << " " << 0;
    return 0;
  }
}
