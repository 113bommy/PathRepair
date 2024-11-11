#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int two = 0, one = 0;
  int x[n + 1000];
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) {
    if (x[i] == 2)
      ++two;
    else
      ++one;
  }
  if (two == 0) {
    for (int i = 0; i < one; ++i) cout << "2 ";
  } else if (one == 0) {
    for (int i = 0; i < two; ++i) cout << "1 ";
  } else {
    --two;
    cout << "2 ";
    --one;
    cout << "1 ";
    for (int i = 0; i < two; ++i) cout << "2 ";
    for (int i = 0; i < one; ++i) cout << "1 ";
  }
}
