#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int D() {
  int m;
  cin >> m;
  return m;
}
inline long long lD() {
  long long m;
  cin >> m;
  return m;
}
inline double dD() {
  double m;
  cin >> m;
  return m;
}
int arr1[1000006], arr2[1000006], arr3[1000006];
int main() {
  fast();
  int n = D();
  for (int i = 0; i < n; ++i) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n - 1; ++i) cin >> arr2[i];
  for (int i = 0; i < n - 2; ++i) cin >> arr3[i];
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + n - 1);
  sort(arr3, arr3 + n - 2);
  bool f = true;
  for (int i = 0; i < n - 1; ++i) {
    if (arr1[i] != arr2[i]) {
      cout << arr1[i] << "\n";
      f = false;
      break;
    }
  }
  if (f)
    cout << arr1[n - 1] << "\n";
  else
    f = true;
  for (int i = 0; i < n - 2; ++i) {
    if (arr2[i] != arr3[i]) {
      cout << arr2[i] << "\n";
      f = false;
      break;
    }
  }
  cout << arr2[n - 2] << "\n";
}
