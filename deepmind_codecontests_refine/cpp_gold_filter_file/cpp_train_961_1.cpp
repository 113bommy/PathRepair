#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> arr(100001);
  vector<int> b(100001);
  int i, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (arr[0] > 1) {
    cout << "-1\n";
    return 0;
  }
  vector<bool> present(n, false);
  vector<bool> f(n, false);
  deque<int> q;
  if (arr[0] == 0) {
    b[0] = 99999;
    present[1] = false;
    q.push_back(0);
    f[0] = true;
  } else {
    b[0] = 0;
    present[0] = true;
  }
  int flag = 1;
  for (i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      b[i] = b[i - 1];
      f[i] = true;
      q.push_back(i);
      continue;
    }
    b[i] = arr[i - 1];
    present[arr[i - 1]] = true;
    for (int j = arr[i - 1] + 1; j < arr[i]; j++) {
      if (present[j] == false) {
        if (q.empty()) {
          flag = 0;
          break;
        }
        int index = q.front();
        q.pop_front();
        b[index] = j;
        f[index] = false;
      }
    }
    if (flag == 0) {
      break;
    }
  }
  if (flag == 0) {
    cout << -1 << "\n";
    return 0;
  }
  for (i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
