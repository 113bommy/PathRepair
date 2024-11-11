#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0, l = 0, c = 0;
  cin >> n;
  while (n > 0) {
    i++;
    c = l + i;
    l = c;
    n = n - c;
    if (n < 0) {
      i--;
    }
  }
  cout << i;
}
