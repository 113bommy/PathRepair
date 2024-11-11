#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  b[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
    b[i] = (b[i + 1]) > (a[i]) ? (b[i + 1]) : (a[i]);
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i + 1])
      cout << 0 << " ";
    else
      cout << b[i + 1] - a[i] + 1 << " ";
  }
  cout << "\n";
  return 0;
}
