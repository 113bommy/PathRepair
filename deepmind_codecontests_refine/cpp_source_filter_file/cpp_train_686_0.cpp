#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int arr1[n];
  int arr2[m];
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < m; i++) cin >> arr2[i];
  int m1 = *min_element(arr1, arr1 + n);
  int m2 = *min_element(arr2, arr2 + m);
  int c = 0, ma = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr1[i] == arr2[j]) ma = ma == -1 ? arr1[i] : min(arr1[i], ma);
    }
  }
  if (m != -1) c = 1;
  if (c)
    cout << ma << "\n";
  else {
    int a = min(m1, m2);
    int b = max(m1, m2);
    cout << a << b << "\n";
  }
  return 0;
}
