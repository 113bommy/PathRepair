#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  printf("%d %d %.15f\n", a / b, a % b, a / (double)b);
}
