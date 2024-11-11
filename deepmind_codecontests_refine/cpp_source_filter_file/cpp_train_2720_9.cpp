#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if ((n * (n - 1) / 2) % 2 == 0)
    cout << "0";
  else
    cout << "1";
}
