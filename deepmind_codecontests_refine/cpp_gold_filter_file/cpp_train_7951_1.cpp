#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, i, j;
  cin >> n;
  for (i = 1; i < n + 1; ++i) {
    for (j = i; j < n + 1; ++j) {
      int x = sqrt(i * i + j * j);
      if (x <= n && x >= j && x * x == (i * i + j * j)) a++;
    }
  }
  cout << a;
}
