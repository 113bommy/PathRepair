#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, b = 0, p = 0;
  cin >> n >> k;
  while (n--) {
    string s;
    cin >> s;
    long long int i, y, a[11] = {0};
    char x;
    for (i = 0; i < s.length(); i++) {
      x = s[i];
      { a[x - 48]++; }
    }
    {
      for (i = 0; i <= k; i++) {
        if (a[i] >= 1) {
          y++;
        }
      }
      if (y == k + 1) {
        p++;
      }
    }
  }
  cout << p;
}
