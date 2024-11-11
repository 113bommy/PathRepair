#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], cnt[N];
int n, k;
int main() {
  int maxn = 0;
  int ans = 0;
  int l = 0;
  int temp;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &temp);
    if (temp != a[i - 1]) {
      a[++l] = temp;
    }
  }
  for (int i = 2; i <= l; i++) {
    if (a[i - 1] == a[i + 1]) {
      cnt[a[i]] += 2;
    } else {
      cnt[a[i]]++;
    }
  }
  maxn = cnt[1];
  ans = 1;
  for (int i = 2; i <= k; i++) {
    if (cnt[i] > maxn) {
      maxn = cnt[i];
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
