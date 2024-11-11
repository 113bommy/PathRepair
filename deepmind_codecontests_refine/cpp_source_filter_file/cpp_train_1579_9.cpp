#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int one = 0, two = 0, temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == 2)
      two++;
    else
      one++;
  }
  if (one == 0) {
    for (int i = 0; i < n; i++) cout << 2 << " ";
    return 0;
  } else if (two == 0) {
    for (int i = 0; i < n; i++) cout << 1 << " ";
    return 0;
  }
  cout << 2 << " " << 1 << " ";
  for (int i = 2; i < n; i++) {
    if (two > 0) {
      cout << 2 << " ";
      two--;
    } else {
      cout << 1 << " ";
    }
  }
  return 0;
}
