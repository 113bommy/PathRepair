#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n %= 1000;
  if (n & 1)
    cout << 1 << endl;
  else
    cout << 2 << endl;
}
