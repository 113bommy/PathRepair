#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, t, r;
  cin >> n >> x >> y;
  if (y < n || x > n - 1 + (y - n + 1) * (y - n + 1))
    cout << "-1\n";
  else {
    for (int i = 0; i < n - 1; i++) cout << 1 << endl;
    cout << y - n + 1 << endl;
  }
  scanf(" ");
}
