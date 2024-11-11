#include <bits/stdc++.h>
using namespace std;
int arr[512345], n;
int ma;
void dfs(int l, int r, int st) {
  if (st == n - 2 && l == r && arr[st] != l) {
    ma = max(ma, 1);
    arr[st] = l;
    return;
  } else if (st <= n - 3 && arr[st] == arr[st + 1]) {
    dfs(arr[st], r, st + 1);
  } else if (st <= n - 2 && arr[st] != arr[st + 1]) {
    int tr = r, t1 = st;
    while (t1 < n - 1 && arr[t1] != arr[t1 + 1]) t1++;
    if (t1 < n - 1) tr = arr[t1 + 1];
    if (l == tr) {
      ma = max(ma, (t1 - st) / 2);
      while (st < t1) arr[st++] = l;
    } else {
      ma = max(ma, (t1 - st + 1) / 2 - 1);
      for (int i = 0; i < (t1 - st) / 2 + 1; i++) arr[st + i] = l;
      for (int i = (t1 - st) / 2 + 1; i < (t1 - st); i++) arr[st + i] = r;
    }
    dfs(tr, r, t1 + 1);
    return;
  }
  return;
}
int main() {
  scanf("%d", &n);
  ;
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  ;
  ma = 0;
  dfs(arr[0], arr[n - 1], 0);
  cout << ma << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}
