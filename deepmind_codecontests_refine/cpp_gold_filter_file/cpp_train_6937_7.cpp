#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  int l, r, pos;
  cin >> n >> pos >> l >> r;
  int arr[200] = {0};
  for (int i = 1; i <= n; i++) arr[i] = 1;
  int toleft = 0, toright = 0;
  int ans = 2;
  if (pos <= r && pos >= l) {
    for (int i = pos + 1; i <= r; i++) {
      toright++;
    }
    if (arr[r + 1] == 0) {
      toright = 0;
      ans--;
    }
    for (int i = pos - 1; i >= l; i--) {
      toleft++;
    }
    if (arr[l - 1] == 0) {
      toleft = 0;
      ans--;
    }
    if (arr[r + 1] == 1 && arr[l - 1] == 1)
      ans += min(toleft, toright) + (r - l);
    else
      ans += max(toleft, toright);
    cout << ans;
  } else if (pos >= r && pos >= l) {
    for (int i = pos - 1; i >= r; i--) {
      toright++;
    }
    if (arr[r + 1] == 0) {
      ans--;
    }
    for (int i = pos - 1; i >= l; i--) {
      toleft++;
    }
    if (arr[l - 1] == 0) {
      ans--;
    }
    if (arr[r + 1] == 1 && arr[l - 1] == 1)
      ans += max(toleft, toright);
    else
      ans += min(toleft, toright);
    cout << ans;
  } else if (pos <= r && pos <= l) {
    for (int i = pos + 1; i <= r; i++) {
      toright++;
    }
    if (arr[r + 1] == 0) {
      ans--;
    }
    for (int i = pos + 1; i <= l; i++) {
      toleft++;
    }
    if (arr[l - 1] == 0) {
      ans--;
    }
    if (arr[r + 1] == 1 && arr[l - 1] == 1)
      ans += max(toleft, toright);
    else
      ans += min(toleft, toright);
    cout << ans;
  }
}
