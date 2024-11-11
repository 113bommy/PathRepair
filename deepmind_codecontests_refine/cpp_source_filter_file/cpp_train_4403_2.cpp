#include <bits/stdc++.h>
using namespace std;
int n, *arr;
int a[50];
void solve() {
  int count = 0, k = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      count++;
      a[k] = i;
      k++;
    }
  }
  if (count == 0 || count == 1 || count == n)
    cout << "0";
  else {
    int i = 0;
    while (i < count - 1) {
      res = res + a[i + 1] - a[i] - 1;
      i++;
    }
    cout << res << endl;
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    arr = (int*)calloc(n, sizeof(arr));
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve();
  }
}
