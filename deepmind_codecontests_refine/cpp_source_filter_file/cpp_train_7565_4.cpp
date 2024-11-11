#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, l, x = 0, y;
  string s;
  cin >> n >> s;
  int a[n];
  j = 0;
  l = s.length();
  for (i = 2; i <= n; i++) {
    if (n % i == 0) {
      a[j] = i;
      j++;
      x++;
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < a[i] / 2; j++) {
      swap(s[j], s[a[i] - i - 1]);
    }
  }
  cout << s << endl;
  return 0;
}
