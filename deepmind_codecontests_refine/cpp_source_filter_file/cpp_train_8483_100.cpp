#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ans = min(a, b);
  int anss = abs(a - b) / 2;
  printf("5d %d", ans, anss);
  return 0;
}
