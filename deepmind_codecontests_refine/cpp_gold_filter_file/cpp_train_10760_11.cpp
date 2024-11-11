#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[1000] = {0}, seg[k];
  for (int i = 0; i < k; i++) {
    cin >> seg[i];
    arr[seg[i]] = 1;
  }
  int x = 1;
  for (int i = 0; i < k; i++) {
    cout << seg[i];
    for (int j = 1; j < n; j++) {
      while (arr[x]) {
        x++;
      }
      cout << " " << x;
      arr[x] = 1;
    }
    cout << endl;
  }
  return 0;
}
