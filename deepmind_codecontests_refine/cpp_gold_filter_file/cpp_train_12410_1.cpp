#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  bool o[100];
  int n, k1, k2;
  int a[100];
  int b[100];
  for (int j = 0; j < t; j++) {
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) cin >> a[i];
    for (int i = 0; i < k2; i++) cin >> b[i];
    o[j] = 0;
    for (int i = 0; i < k1; i++)
      if (a[i] == n) o[j] = 1;
  }
  for (int j = 0; j < t; j++) {
    if (o[j])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
