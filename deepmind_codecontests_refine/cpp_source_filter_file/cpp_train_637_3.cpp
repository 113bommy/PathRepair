#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr1[n], arr2[n];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }
  int o = 0, e = 0, o1 = 0, e1 = 0;
  for (int i = 0; i < n; i++) {
    if (arr1[i] % 2)
      o++;
    else
      e++;
  }
  for (int i = 0; i < m; i++) {
    if (arr2[i] % 2)
      o1++;
    else
      e1++;
  }
  cout << min(e, o1) + min(o, e1);
}
