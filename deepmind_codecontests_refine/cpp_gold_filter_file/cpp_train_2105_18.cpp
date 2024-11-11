#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n];
  int L = 0;
  int R = 0;
  int s = 1;
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 'L') {
      L++;
      x--;
      s++;
    } else if (a[i] == 'R') {
      R++;
      x++;
      s++;
    }
  }
  if (L == R)
    cout << n + 1 << endl;
  else
    cout << s << endl;
  return 0;
}
