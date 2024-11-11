#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int mn = n, z = n;
  for (int i = 0; i < k; i++) {
    char c = s[i];
    int x = -1, y = -1;
    for (int j = i; j < n; j += k) {
      if (s[j] < c) {
        s[j] = c;
        mn = min(mn, j);
      }
      if (s[j] > c && j < mn) {
        if (x == -1 && y == -1) {
          x = j - k;
          y = j - i - 1;
        }
      }
      s[j] = c;
    }
    if (x != -1 && y != -1) {
      for (int j = y; j >= x; j--) {
        if (s[j] != '9') {
          z = min(z, j);
          break;
        }
      }
    }
  }
  if (z != n && z % k < mn) {
    s[z % k]++;
    for (int i = z + 1; i < k; i++) {
      s[i] = '0';
    }
    for (int i = 0; i < k; i++) {
      char c = s[i];
      for (int j = i; j < n; j += k) {
        s[j] = c;
      }
    }
  }
  cout << n << "\n";
  cout << s << "\n";
  return 0;
}
