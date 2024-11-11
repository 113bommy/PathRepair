#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n++;
  if (n == 1)
    cout << 0 << endl;
  else
    cout << ((n % 2) ? n : (n / 2)) << endl;
}
