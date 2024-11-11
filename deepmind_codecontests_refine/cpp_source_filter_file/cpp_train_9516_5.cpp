#include <bits/stdc++.h>
using namespace std;
int main() {
  int v;
  cin >> v;
  pair<int, int> arr[9];
  for (int i = 0; i < 9; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  sort(arr, arr + 9);
  int num[10] = {};
  num[arr[0].second] = v / arr[0].first;
  v = v % arr[0].first;
  int dig = arr[0].second;
  int val = arr[0].first;
  for (int i = 0; i < 8; i++) {
    swap(arr[i].first, arr[i].second);
  }
  sort(arr, arr + 9);
  for (int i = 8; i >= 0 && arr[i].first > dig; i--) {
    while (num[dig] > 0 && v >= arr[i].second - val) {
      num[dig]--;
      num[arr[i].first]++;
      v -= arr[i].second - val;
    }
  }
  bool flag = false;
  for (int i = 9; i >= 1; i--) {
    while (num[i]--) {
      flag = true;
      cout << (char)(i + '0');
    }
  }
  if (!flag) {
    cout << -1;
  }
  return 0;
}
