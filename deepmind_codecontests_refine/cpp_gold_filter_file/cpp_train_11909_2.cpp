#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  if (n % 2 == 0) return cout << -1, 0;
  for (int i = 0; i < n; i++) cout << i << " \n"[i == n - 1];
  int j = n / 2, k = n - 1;
  for (int i = 0; i < n; i++)
    cout << (i & 1 ? k-- : j--) << " \n"[i == n - 1],
        a[i] = (i + (i & 1 ? k + 1 : j + 1)) % n;
  for (int i : a) cout << i << " ";
}
