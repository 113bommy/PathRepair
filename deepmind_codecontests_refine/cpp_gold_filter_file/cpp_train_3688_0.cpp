#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  int d[n - 1];
  for (int i = 0; i < n - 1; i++) cin >> d[i];
  int a, b;
  cin >> a >> b;
  int x = b - a;
  for (int i = a - 1; i < x + a - 1; i++) count += d[i];
  cout << count;
  return 0;
}
