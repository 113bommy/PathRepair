#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans[100005];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    ans[i] = 1000000000;
  }
  int j = -1000000000;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      j = i;
    }
    ans[i] = min(ans[i], i - j);
  }
  j = 1000000000;
  for (int i = n - 1; i > -1; --i) {
    if (a[i] == 0) {
      j = i;
    }
    ans[i] = min(ans[i], j - i);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
