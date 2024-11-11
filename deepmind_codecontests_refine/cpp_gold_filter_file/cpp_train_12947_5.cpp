#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], b[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] != a[i + 1]) sum++;
  }
  int i = 1;
  while (i <= n) {
    ;
    int now = i;
    while ((a[i + 1] == a[i]) && (i < n)) i++;
    if (a[now - 1] == a[i + 1])
      b[a[i]] += 2;
    else
      b[a[i]]++;
    ;
    ;
    ;
    ;
    ;
    ;
    i++;
  }
  int ans = 1;
  for (int i = 1; i <= k; i++)
    if (b[i] > b[ans]) ans = i;
  ;
  for (int i = 1; i <= k; i++)
    ;
  cout << ans << endl;
}
