#include <bits/stdc++.h>
using namespace std;
int arr[110];
int main() {
  int n, m;
  int temp, res;
  int mx;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    mx = 0;
    for (int j = 0; j < n; ++j) {
      cin >> temp;
      if (temp > mx) {
        mx = temp;
        ;
        res = j;
      }
    }
    arr[res]++;
  }
  mx = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > mx) {
      mx = arr[i];
      res = i + 1;
    }
  }
  cout << res << endl;
  return 0;
}
