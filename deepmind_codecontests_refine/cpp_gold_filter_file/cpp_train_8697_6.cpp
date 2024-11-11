#include <bits/stdc++.h>
using namespace std;
int n, a, r = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    r = (r + a - 1) % 2;
    cout << ((r) ? "1\n" : "2\n");
  }
  return 0;
}
