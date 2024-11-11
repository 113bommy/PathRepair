#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if ((n * (n + 1)) / 2 % 2 == 0)
    cout << 0;
  else
    cout << 1;
}
