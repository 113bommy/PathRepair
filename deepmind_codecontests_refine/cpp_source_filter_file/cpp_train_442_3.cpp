#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  stack<int> pa[4];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  };
  int chse[n], chsed[n];
  for (int i = 0; i < n; i++) chse[i] = chsed[i] = i;
  bool flag = 1;
  int num = 0;
  for (int i = n - 1; flag && i >= 0; i--) {
    int cur = arr[i];
    if (cur == 0) continue;
    if (cur == 1) pa[1].push(i), num++;
    if (cur == 2) {
      if (pa[1].empty()) {
        flag = 0;
        break;
      };
      int p = pa[1].top();
      pa[1].pop();
      chsed[p] = i;
      chse[i] = p;
      pa[2].push(i);
      num++;
    }
    if (cur == 3) {
      int p = -1;
      for (int j = 3; j >= 1 && p == -1; j--) {
        if (!pa[j].empty()) {
          p = pa[j].top();
          pa[j].pop();
        }
      }
      if (p == -1) {
        flag = 0;
        break;
      }
      chse[i] = p;
      chsed[p] = i;
      pa[3].push(i);
      num += 2;
    }
  }
  if (!flag) {
    cout << "-1\n";
    return 0;
  }
  cout << num << "\n";
  int row = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] == 0) continue;
    if (arr[i] == 1) {
      cout << row << ' ' << i + 1 << "\n";
      if (chsed[i] != i && arr[chsed[i]] == 2)
        cout << row << ' ' << chsed[i] + 1 << "\n";
      row++;
    }
    if (arr[i] == 2) continue;
    if (arr[i] == 3) {
      cout << row << ' ' << i + 1 << "\n";
      cout << row++ << ' ' << chse[i] + 1 << "\n";
    }
  }
  return 0;
}
