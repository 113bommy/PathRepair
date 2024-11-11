#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, j, i, t;
  cin >> a >> b;
  i = min(a, b);
  j = (max(a, b) - i) / 2;
  cout << i << j;
}
