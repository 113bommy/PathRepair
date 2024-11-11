#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  int a[n];
  int mn = -1;
  int indexMin = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) mn = max(mn, a[i] - a[i + 1]);
  if (mn == -1 || mn - c < 0)
    cout << "0";
  else
    cout << mn - c;
  return 0;
}
