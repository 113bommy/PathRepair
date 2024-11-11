#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n - 1; i++) cout << b[i] + b[i + 1] << ' ';
  cout << b[n - 1] << ' ';
}
