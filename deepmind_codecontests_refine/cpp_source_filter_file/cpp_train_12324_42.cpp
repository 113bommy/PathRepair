#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = 0;
  cin >> n;
  char c[3];
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c[1] == '+')
      p++;
    else
      p--;
  }
  cout << p;
  return 0;
}
