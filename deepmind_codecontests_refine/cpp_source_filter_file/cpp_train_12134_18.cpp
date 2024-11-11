#include <bits/stdc++.h>
using namespace std;
int n, a[100005], x = 1, y;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1])
      x++;
    else
      x = 1;
    y = max(x, y);
  }
  cout << y;
  return 0;
}
