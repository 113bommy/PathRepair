#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100005], MAX = 0, n, l;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l;
    a[l] = a[l - 1] + 1;
    MAX = max(MAX, a[l]);
  }
  cout << n - MAX << endl;
  return 0;
}
