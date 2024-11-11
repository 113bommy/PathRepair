#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    arr[x] = i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(arr[i] - arr[i + 1]);
  }
  cout << ans << endl;
}
