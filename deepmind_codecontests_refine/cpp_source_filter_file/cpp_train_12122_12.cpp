#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[m], art[m], mini = n + 2;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    art[i] = arr[i];
  }
  for (int i = 0; i < m - 1; i++) {
    if (arr[i] < mini) {
      mini = arr[i];
    }
    if (arr[i] > mini) art[i] = -1;
  }
  sort(art, art + m);
  for (int i = 1; i <= n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (art[j] <= i && art[j] != -1) {
        cout << art[j] << " ";
        break;
      }
    }
  }
  return 0;
}
