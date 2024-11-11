#include <bits/stdc++.h>
using namespace std;
int arr[400000];
int solve(void) {
  int n;
  int i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int prev = arr[0], cnt = 0, pos = 0;
  for (i = 1; i < n; i++) {
    if (prev != arr[i]) {
      prev = arr[i];
      pos = i - 1;
    }
    cnt++;
    if (cnt == n / 2) {
      break;
    }
  }
  if (prev == arr[i + 1]) {
    prev = arr[pos];
  } else {
    pos = i;
  }
  prev = arr[pos];
  int g = 1, s = 0, b = 0;
  int cur = arr[0];
  for (i = 1; i <= pos; i++) {
    if (cur == arr[i])
      g++;
    else {
      cur = arr[i];
      break;
    };
  }
  for (; i <= pos; i++) {
    if (s <= g) {
      s++;
      cur = arr[i];
    } else if (cur == arr[i]) {
      s++;
    } else
      break;
  }
  b = pos - i + 1;
  if (g < s && g < b) {
    cout << g << " " << s << " " << b << endl;
  } else
    cout << "0 0 0\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
