#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n < 13)
      cout << (1LL << n) << endl;
    else
      cout << (8092LL << (n - 13)) << endl;
  }
}
