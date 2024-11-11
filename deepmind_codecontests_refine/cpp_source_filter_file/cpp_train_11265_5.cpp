#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int shamne[n], pos = 0;
  int pisone[n];
  shamne[0] = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1])
      shamne[i] = shamne[i - 1] + 1;
    else {
      shamne[i] = 1;
      for (int j = i - 1; j >= pos; j--) pisone[j] = cnt++;
      pos = i;
      cnt = 1;
    }
  }
  for (int j = n - 1; j >= pos; j--) pisone[j] = cnt++;
  int ans = 1;
  if (arr[1] > arr[0]) ans = 2;
  for (int i = 2; i < n; i++) {
    if (arr[i] < arr[i - 1] && arr[i] > arr[i - 2]) {
      ans = max(shamne[i - 2] + pisone[i], ans);
    }
    if (i < n - 1 && arr[i] < arr[i - 1] && arr[i + 1] > arr[i - 1]) {
      ans = max(shamne[i - 1] + pisone[i + 1], ans);
    }
    ans = max(shamne[i], ans);
  }
  cout << ans << endl;
}
