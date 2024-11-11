#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int pos, int n) {
  int i, cnt = 1;
  bool downDirection = false;
  for (i = pos + 1; i < n; i++) {
    if (arr[i] > arr[i - 1] && !downDirection) {
      cnt++;
    } else if (arr[i] < arr[i - 1]) {
      cnt++;
      downDirection = true;
    } else if (arr[i] == arr[i - 1]) {
      cnt++;
    } else if (arr[i] > arr[i - 1] && downDirection)
      return cnt;
  }
  return cnt;
}
int main() {
  int i, j, n, cnt = 0;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<int> vec;
  for (i = 0; i < n; i++) {
    int var = maxLen(arr, i, n);
    vec.push_back(var);
  }
  cout << *max_element(vec.begin(), vec.end()) << endl;
  return 0;
}
