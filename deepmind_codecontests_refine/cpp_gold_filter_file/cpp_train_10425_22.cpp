#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a <= (n / 2) - 1 || a >= (n / 2) + 2 || b <= (n / 2) - 1 ||
      b >= (n / 2) + 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
