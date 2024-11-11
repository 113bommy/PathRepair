#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n < 14)
      cout << (1LL << n) << endl;
    else
      cout << (16184LL << (n - 14)) << endl;
  }
}
