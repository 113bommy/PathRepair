#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x > y) a++;
    if (x < y) b++;
  }
  if (a > b) puts("Mishka");
  if (a == b) puts("Friendship is magic!^^");
  if (a < b) puts("Chris");
  return 0;
}
