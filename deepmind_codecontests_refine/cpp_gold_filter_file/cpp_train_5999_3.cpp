#include <bits/stdc++.h>
using namespace std;
int n;
int a[33];
int my = -10009;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    my = max(my, a[i]);
  }
  int ans = my - 25;
  cout << max(0, ans);
}
