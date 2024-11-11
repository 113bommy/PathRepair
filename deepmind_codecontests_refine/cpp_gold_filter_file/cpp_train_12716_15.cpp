#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  int cnt = min(a, b);
  cout << 2 * (c + cnt) + (a != b) << endl;
}
