#include <bits/stdc++.h>
using namespace std;
int SD() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int n = SD(), n2 = n, t = SD(), k = SD(), d = SD();
  puts(n - (d / t) * k > k ? "YES" : "NO");
}
