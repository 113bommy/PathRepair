#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, arr[101] = {};
  scanf("%d%d%d", &n, &a, &b);
  int alex[b], au[a];
  for (int i = 1; i <= a; i++) {
    cin >> au[i];
    arr[au[i]] = 1;
  }
  for (int i = 1; i <= b; i++) {
    cin >> alex[i];
    if (arr[alex[i]] == 1)
      arr[alex[i]] = 1;
    else
      arr[alex[i]] = 2;
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
