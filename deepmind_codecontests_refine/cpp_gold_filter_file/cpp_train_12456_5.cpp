#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  int i, j;
  for (i = 1; i <= n; i++) cin >> arr[i];
  int first, second, th, fil, sel, thl;
  for (i = 1; i <= n; i++) {
    first = i;
    fil = arr[first];
    second = arr[first];
    sel = arr[second];
    th = arr[second];
    thl = arr[arr[second]];
    if (thl == first) {
      cout << "YES"
           << "\n";
      return 0;
    }
  }
  cout << "NO"
       << "\n";
  return 0;
}
