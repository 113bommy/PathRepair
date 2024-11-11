#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int a = 21; a <= 50; ++a)
    cout << (((min(a, 25) + a) % (2 + (a % 3))) > 0) << endl;
  return 0;
}
