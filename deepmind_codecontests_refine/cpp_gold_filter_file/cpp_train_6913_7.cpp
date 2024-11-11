#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, d;
  cin >> k >> d;
  if (d) {
    cout << d;
    for (int i = 1; i < k; i++) putchar('0');
  } else if (k == 1)
    cout << 0;
  else
    cout << "No solution";
  return 0;
}
