#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, i, lcount = 0, wcount = 0, d = 0;
  int a[50];
  int b[50];
  cin >> n >> c;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (i = 0; i < n; i++) {
    d = d + b[i];
    lcount += max(0, (a[i] - c * d));
  }
  d = 0;
  for (i = n - 1; i >= 0; i--) {
    d = d + b[i];
    wcount += max(0, (a[i] - c * d));
  }
  if (lcount == wcount) {
    cout << "Tie";
  }
  if (lcount > wcount) {
    cout << "Limak";
  }
  if (lcount < wcount) {
    cout << "Radewoosh";
  }
}
