#include <bits/stdc++.h>
using namespace std;
int dX[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dY[] = {0, 1, 0, -1, 1, 1, -1, -1};
inline void Refresh() {}
long long int a[100007];
long long int X[100007];
int main() {
  bool diffFound = false;
  long long int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long int lft, ryt;
  long long int finalVal;
  long long int toAdd;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] != a[i + 1]) {
      lft = min(a[i], a[i + 1]);
      ryt = max(a[i], a[i + 1]);
      diffFound = true;
    }
  }
  if (!diffFound) {
    cout << "YES" << endl;
    return 0;
  }
  bool isPossible;
  isPossible = true;
  finalVal = lft;
  for (int i = 0; i < n; ++i) {
    X[i] = abs(finalVal - a[i]);
  }
  toAdd = 0;
  for (int i = 0; i < n; ++i) {
    if (X[i] != 0) {
      toAdd = X[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (X[i] == 0) continue;
    if (X[i] != toAdd) {
      isPossible = false;
      break;
    }
  }
  if (isPossible) {
    cout << "YES" << endl;
    return 0;
  }
  isPossible = true;
  finalVal = ryt;
  for (int i = 0; i < n; ++i) {
    X[i] = abs(finalVal - a[i]);
  }
  toAdd = 0;
  for (int i = 0; i < n; ++i) {
    if (X[i] != 0) {
      toAdd = X[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (X[i] == 0) continue;
    if (X[i] != toAdd) {
      isPossible = false;
      break;
    }
  }
  if (isPossible) {
    cout << "YES" << endl;
    return 0;
  }
  isPossible = true;
  if ((ryt - lft) % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }
  finalVal = (ryt - lft) / 2;
  for (int i = 0; i < n; ++i) {
    X[i] = abs(finalVal - a[i]);
  }
  toAdd = 0;
  for (int i = 0; i < n; ++i) {
    if (X[i] != 0) {
      toAdd = X[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (X[i] == 0) continue;
    if (X[i] != toAdd) {
      isPossible = false;
      break;
    }
  }
  if (isPossible) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
