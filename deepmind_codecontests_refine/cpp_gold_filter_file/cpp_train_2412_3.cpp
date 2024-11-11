#include <bits/stdc++.h>
using namespace std;
long long x;
int main() {
  cin >> x;
  if (x % 2 == 0 || x < 4)
    cout << "NO\n";
  else
    cout << "1 " << (x - 3) / 2 << endl;
}
