#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, lim1, lim2, arr[100];
  cin >> n;
  n--;
  cin >> lim1;
  lim2 = lim1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(&arr[0], &arr[n - 1]);
  while (arr[n - 1] >= lim2) {
    arr[n - 1]--;
    lim2++;
    sort(&arr[0], &arr[n]);
  }
  cout << (lim2 - lim1);
  return 0;
}
