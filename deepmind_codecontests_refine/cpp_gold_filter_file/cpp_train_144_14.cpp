#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
int main() {
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ma = -1;
  for (int i = 0; i < n - 1; i++)
    if (a[i] - a[i + 1] - c > ma) ma = a[i] - a[i + 1] - c;
  cout << max(ma, 0) << endl;
  return 0;
}
