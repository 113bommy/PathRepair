#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long X, Y;
  cin >> X >> Y;
  cout << (long long)log2(Y / X) + 1 << endl;
}
