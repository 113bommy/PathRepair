#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, i;
  scanf("%d%d", &a, &b);
  n = a + b + 1;
  for (i = 1; i < a; i++) {
    cout << i << " ";
  }
  cout << n << " ";
  for (i = 1; i <= b; i++) cout << n - i << ' ';
}
