#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k;
int a[maxn];
int sum[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] = 1 - a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int OKans = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    int l = i, r = n;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (sum[mid] - sum[i - 1] > k) {
        r = mid - 1;
      } else {
        l = mid + 1, ans = mid - i + 1;
      }
    }
    if (OKans < ans) {
      OKans = ans;
      ans2 = i;
    }
  }
  cout << OKans << endl;
  for (int i = ans2; i <= n; i++) {
    if (OKans == 0) {
      break;
    }
    if (a[i] == 1) {
      a[i] = 0;
    }
    if (a[i] == 0) {
      OKans--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << i - a[i] << " ";
  }
}
