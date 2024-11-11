#include <bits/stdc++.h>
using namespace std;
int n;
int arr[30000];
int ans[3000 * 3000 + 7];
int main() {
  scanf("%d ", &n);
  for (int i = 0; i < n; i++) scanf("%d ", &arr[i]);
  int c = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (arr[i] > arr[j]) c++;
  ans[0] = 0;
  ans[1] = 1;
  for (int i = 2; i <= c; i++) ans[i] = 4 + ans[i - 2];
  cout << ans[c] << endl;
}
