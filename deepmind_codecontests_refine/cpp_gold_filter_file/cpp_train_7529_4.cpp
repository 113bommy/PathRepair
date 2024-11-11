#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  long int s = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a;
      if (i == j || i + j + 1 == n || i == n / 2 || j == n / 2) s += a;
    }
  }
  cout << s;
  return 0;
}
