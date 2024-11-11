#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string k;
  int x = sqrt(2 * n);
  int l = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (x > 0) {
      k[l] = s[i + j];
      cout << k[l];
      j += i;
      l++;
      x--;
    }
  }
  return 0;
}
