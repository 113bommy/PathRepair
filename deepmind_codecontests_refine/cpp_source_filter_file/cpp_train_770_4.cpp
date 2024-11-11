#include <bits/stdc++.h>
using namespace std;
void in() {}
int main() {
  in();
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << "\n";
  else
    cout << (int)sqrt(n) * n * 4 << "\n";
}
