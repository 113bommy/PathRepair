#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, y = 0;
  char s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == 'A') {
      x += 1;
    } else
      y += 1;
  }
  if (x > y) {
    cout << "Anton";
  } else if (x < y) {
    cout << "Danik";
  } else
    cout << "Friendship";
}
