#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[50];
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> m[i];
  sort(m, m + n);
  int r = 0;
  for (int i = n - 1; i >= 0; i--) {
    r++;
    if (r == k) {
      cout << m[i] << " " << m[i] - 1;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
