#include <bits/stdc++.h>
using namespace std;
const int xn = 1e5 + 20;
long long n, a[xn];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cout << a[i] + a[i + 1] << ' ';
  return 0;
}
