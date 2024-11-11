#include <bits/stdc++.h>
using namespace std;
bool sol(int x) {
  if (x == 2) return true;
  if (x == 3) return true;
  if (x == 4) return true;
  if (x == 5) return true;
  if (x == 12) return true;
  if (x == 30) return true;
  if (x == 31) return true;
  if (x == 35) return true;
  if (x == 43) return true;
  if (x == 46) return true;
  if (x == 52) return true;
  if (x == 55) return true;
  if (x == 64) return true;
  if (x < 82) return false;
  if (x == 86) return true;
  if (x == 13) return false;
  if (x == 24) return false;
  return false;
}
int n;
int main() {
  cin >> n;
  puts(sol(n) ? "YES" : "NO");
  return 0;
}
