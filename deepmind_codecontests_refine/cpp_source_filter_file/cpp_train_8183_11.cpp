#include <bits/stdc++.h>
using namespace std;
int a[3000009], vis[3000009];
int curr, mum;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n + 1; i++) {
    while (curr < n && vis[n - curr]) curr++;
    printf("%d", i - curr);
    vis[a[i]] = 1;
  }
}
