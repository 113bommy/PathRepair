#include <bits/stdc++.h>
using namespace std;
int pos[300000];
int mp[300000];
int main() {
  int n;
  cin >> n;
  int a[n + 10], b[n + 10];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    int x = pos[b[i]] - i;
    if (x < 0) x = n + x;
    mp[x]++;
  }
  int mx = 0;
  for (int i = 0; i <= n; i++) {
    mx = max(mx, mp[i]);
  }
  cout << mx << endl;
  return 0;
}
