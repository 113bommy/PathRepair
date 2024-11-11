#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, k;
  cin >> n >> k >> m;
  int arr[1000000];
  for (int i = 0; i < m; i++) {
    arr[i] = 10000000;
  }
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    int f;
    cin >> f;
    arr[r - 1] = min(arr[r - 1], f);
  }
  int x = 0;
  for (int i = 0; i < m; i++) {
    if (arr[i] != 10000000) {
      x += arr[i];
    }
  }
  cout << min(m, x) << endl;
}
