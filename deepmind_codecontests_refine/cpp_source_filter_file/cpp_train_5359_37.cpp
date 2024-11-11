#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int b;
  cin >> b;
  vector<int> boy(n, 0);
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    boy[x] = 1;
  }
  int g;
  cin >> g;
  vector<int> girl(m, 0);
  for (int i = 0; i < g; i++) {
    int x;
    cin >> x;
    girl[x] = 1;
  }
  int k = max(n, m);
  int i = 0, j = 0, u = k;
  k += 50;
  while (k--) {
    for (int x = 0; x < m; x++) {
      if (boy[i] == 1 || girl[j] == 1) {
        boy[i] = 1;
        girl[j] = 1;
      }
      if (i == n - 1) i = -1;
      if (j == m - 1) j = -1;
      i++;
      j++;
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (boy[i] == 0) {
      flag = 1;
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    if (girl[i] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
