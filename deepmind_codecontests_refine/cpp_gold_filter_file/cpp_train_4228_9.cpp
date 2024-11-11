#include <bits/stdc++.h>
using namespace std;
int n;
bool isBelong(int a[], int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  int a[1000], b[1000];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int res[1000];
  int index = 0;
  int Count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i])
      res[i] = a[i];
    else {
      res[i] = 0;
      index = i;
      Count++;
    }
  }
  int dp[100000];
  for (int i = 0; i < n; i++) {
    dp[res[i]] = 1;
  }
  vector<int> temp;
  for (int i = 1; i <= n; i++) {
    if (dp[i] != 1) temp.push_back(i);
  }
  bool check = false;
  if (Count == 1) {
    for (int i = 1; i <= n; i++)
      if (dp[i] != 1) res[index] = i;
  } else {
    for (int i = 0; i < n; i++) {
      if (res[i] == 0) {
        res[i] = temp[0];
        res[index] = temp[1];
        if ((res[i] != a[i] && res[i] != b[i]) ||
            (res[index] != a[index] && res[index] != b[index])) {
          res[i] = temp[1];
          res[index] = temp[0];
          break;
        } else
          break;
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", res[i]);
  return 0;
}
