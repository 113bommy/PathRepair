#include <bits/stdc++.h>
using namespace std;
void read() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  read();
  int a, b, v, k, box = 0;
  cin >> k >> a >> b >> v;
  while (a > 0) {
    if (b + 1 > k) {
      a -= (k * v);
      b -= (k - 1);
    } else {
      a -= ((b + 1) * v);
      b = 0;
    }
    box++;
  }
  cout << box << endl;
  return 0;
}
