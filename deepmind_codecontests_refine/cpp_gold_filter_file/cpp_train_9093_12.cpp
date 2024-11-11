#include <bits/stdc++.h>
using namespace std;
int n, h;
pair<int, int> arr[100010];
int res[100010];
int ptr = -1;
int cnt, bits;
int main() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
    res[i] = 1;
  }
  sort(arr, arr + n);
  int ans = arr[n - 1].first + arr[n - 2].first - arr[0].first - arr[1].first;
  for (int i = n - 2; i >= 0; i--) {
    int mx = arr[i].first + arr[n - 1].first + h;
    if (i < n - 2) mx = max(mx, arr[n - 1].first + arr[n - 2].first);
    int init = min(7, i);
    int col[7];
    if (i <= 6) {
      col[i] = 2;
      for (int j = i + 1; j < min(n, 7); j++) col[j] = 1;
    }
    for (int j = 0; j < (1 << init); j++) {
      for (int k = 0; k < init; k++) {
        col[k] = ((j & (1 << k)) ? 1 : 2);
      }
      int mn = 1000000000;
      for (int k = 0; k < min(n, 7); k++) {
        for (int l = k + 1; l < min(n, 7); l++) {
          int val = arr[k].first + arr[l].first;
          if (col[k] != col[l]) val += h;
          mn = min(mn, val);
        }
      }
      int dif = mx - mn;
      if (dif < ans) {
        ans = dif;
        ptr = i;
        cnt = init;
        bits = j;
      }
    }
  }
  if (ptr != -1) {
    for (int i = 0; i < cnt; i++) {
      res[arr[i].second] = ((bits & (1 << i)) ? 1 : 2);
    }
    res[arr[ptr].second] = 2;
    for (int i = ptr + 1; i < n; i++) res[arr[i].second] = 1;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
