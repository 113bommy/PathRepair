#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int arr[x + 1];
  memset(arr, -1, sizeof arr);
  for (int i = 0; i <= x; i++) arr[i] = i;
  int arr2[x + 1];
  memset(arr2, -1, sizeof arr2);
  int cur = y;
  for (int i = 0; i <= x && cur <= y; i++) arr2[i] = cur, cur--;
  int cnt = 0;
  for (int i = 0; i <= x; i++) {
    if (arr[i] != -1 && arr2[i] != -1) cnt++;
  }
  cout << cnt << '\n';
  for (int i = 0; i <= x; i++)
    if (arr[i] != -1 && arr2[i] != -1) cout << arr[i] << ' ' << arr2[i] << '\n';
  return 0;
}
