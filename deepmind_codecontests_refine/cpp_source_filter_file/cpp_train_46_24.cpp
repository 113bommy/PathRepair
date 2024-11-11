#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, arr[100005], ar[100005], a[100005];
  vector<int> v;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n - 1; i++) {
    cin >> ar[i];
  }
  sort(arr, arr + n);
  sort(ar, ar + n - 1);
  for (i = 0; i < n; i++) {
    if (arr[i] != ar[i]) {
      v.push_back(arr[i]);
      break;
    }
  }
  for (i = 0; i < n - 2; i++) {
    cin >> a[i];
  }
  sort(a, a + n - 2);
  for (i = 0; i < n - 1; i++) {
    if (ar[i] != a[i]) {
      v.push_back(arr[i]);
      break;
    }
  }
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  return 0;
}
