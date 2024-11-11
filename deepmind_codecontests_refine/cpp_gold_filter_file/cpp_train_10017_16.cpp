#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, i, c = 0, d = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0)
      c++;
    else
      d++;
  }
  if (d % 2 == 0) {
    cout << c << endl;
    return;
  } else {
    cout << d << endl;
    return;
  }
}
int main() { solve(); }
