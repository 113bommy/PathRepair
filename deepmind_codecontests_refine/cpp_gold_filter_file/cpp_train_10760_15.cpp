#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n, k;
  cin >> n >> k;
  int vis[1000] = {0};
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    vis[a[i]] = 1;
  }
  for (int i = 1; i <= k; i++) {
    cout << a[i];
    int cnt = 0;
    for (int j = 1; cnt != n - 1 && j <= n * k; j++) {
      if (!vis[j]) {
        cout << ' ';
        cout << j;
        vis[j] = 1;
        cnt++;
      }
    }
    cout << endl;
  }
}
