#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> play;
  map<int, int> win;
  int n, x, c = 0, y;
  int a[2];
  cin >> n;
  for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
    cin >> x >> y;
    play[x]++;
    play[y]++;
    win[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (play[i] == n - 2) {
      a[c] = i;
      c++;
    }
  }
  if (win[a[0]] >= win[a[1]])
    cout << a[0] << " " << a[1];
  else
    cout << a[1] << " " << a[0];
}
