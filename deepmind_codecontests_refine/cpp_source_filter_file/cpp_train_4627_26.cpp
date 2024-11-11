#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int b;
  cin >> n >> b;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mini[n];
  mini[0] = a[0];
  for (int i = 1; i < n; i++) {
    mini[i] = min(mini[i - 1], a[i]);
  }
  int maxi = 0;
  for (int i = 1; i < n; i++) {
    maxi = max(maxi, b % mini[i] + (b / mini[i]) * a[i]);
  }
  cout << maxi;
  return 0;
}
