#include <bits/stdc++.h>
using namespace std;
int arr1[200005], arr2[200005];
int BinarySEArch1(int l, int h, int A) {
  while (l < h) {
    int mid = (l + h) / 2;
    if (arr1[mid] > A)
      h = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 1; i <= m; i++) cin >> arr2[i];
  sort(arr1, arr1 + n);
  for (int i = 1; i <= m; i++) {
    cout << BinarySEArch1(0, n - 1, arr2[i]) << " ";
  }
  return 0;
}
