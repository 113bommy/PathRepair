#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  int x = 0;
  int y = 0;
  cin >> n;
  int l[n];
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> m >> c;
    l[i] = m;
    a[i] = c;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < l[i]) {
      x++;
    } else if (l[i] < a[i]) {
      y++;
    } else {
      x++;
      y++;
    }
  }
  if (x > y) {
    cout << "Mishka";
  } else if (x < y) {
    cout << "Chris";
  } else {
    cout << "Friendship is magic!";
  }
  return 0;
}
