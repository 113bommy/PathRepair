#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 85;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cout << a[i] + a[i + 1] << ' ';
  return cout << a[n - 1] << endl, 0;
}
