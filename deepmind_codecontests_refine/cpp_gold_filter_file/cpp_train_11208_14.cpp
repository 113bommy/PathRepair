#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t = 0, p = 0;
  char x[105];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (i = 0; i < n; i++) {
    if (x[i] == 'x') {
      p++;
      if (p >= 3) t++;
    } else
      p = 0;
  }
  cout << t << endl;
  return 0;
}
