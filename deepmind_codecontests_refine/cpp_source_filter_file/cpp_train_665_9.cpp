#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[1001];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int s = 0, d = 0, m, k = 0, i = 0, j = n - 1;
  while (i <= j) {
    if (arr[i] >= arr[j]) {
      m = arr[i];
      i++;
    } else {
      m = arr[j];
      j--;
    }
    if (k % 2) {
      s += m;
    } else {
      d += m;
    }
    k++;
  }
  cout << s << " " << d << endl;
  return 0;
}
