#include <bits/stdc++.h>
using namespace std;
int e[100 + 1];
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (e[i] == 1) continue;
    int dem = 1;
    for (int j = i + 1; j <= n; j++)
      if (e[j] == 0 && a[j] >= dem) {
        dem++;
        e[j] = 1;
      }
    cnt++;
  }
  cout << cnt;
}
