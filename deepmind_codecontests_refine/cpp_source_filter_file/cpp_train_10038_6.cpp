#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long int arr1[3001];
  long int arr2[3001];
  int count = 0;
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < m; i++) cin >> arr2[i];
  int x = 0, y = 0;
  while (x < n && y < m) {
    if (arr1[x] <= arr2[y]) {
      x++;
      y++;
    }
    y++;
  }
  cout << n - x << endl;
  return 0;
}
