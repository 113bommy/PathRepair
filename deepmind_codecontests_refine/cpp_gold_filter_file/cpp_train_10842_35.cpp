#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 21; i <= 50; i++)
    cout << ((min(i, 25) + i) % (2 + (i % 3)) > 0) << endl;
  return 0;
}
