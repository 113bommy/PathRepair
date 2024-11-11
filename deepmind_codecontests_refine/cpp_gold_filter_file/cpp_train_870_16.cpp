#include <bits/stdc++.h>
using namespace std;
void init() {
  ios::sync_with_stdio();
  cin.tie(0);
}
int main() {
  init();
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int m;
  cin >> m;
  int x, y;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    arr[x - 1] += y - 1;
    arr[x + 1] += arr[x] - y;
    arr[x] = 0;
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << '\n';
  return 0;
}
