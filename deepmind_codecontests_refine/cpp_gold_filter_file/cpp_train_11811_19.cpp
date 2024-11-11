#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) a[i] = 1;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    a[x - 1] = 0;
  }
  for (int i = 0; i < n; i++)
    if (a[i]) cout << i + 1;
}
