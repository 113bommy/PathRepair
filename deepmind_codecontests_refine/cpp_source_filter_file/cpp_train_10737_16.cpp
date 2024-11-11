#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int cnt = 0;
  int prev = 0;
  int res = 0;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 1; i < n; ++i) {
    if (arr[i] != arr[i - 1]) {
      prev = cnt;
      cnt = 1;
    } else
      cnt++;
    if (prev < cnt) {
      if (res < prev) res = prev;
    } else {
      if (res < cnt) res = cnt;
    }
  }
  cout << res * 2;
  delete[] arr;
  return 0;
}
