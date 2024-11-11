#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  int t = 0;
  while (b <= a) {
    a += 2;
    b += 3;
    t += 1;
  }
  cout << t;
  return 0;
}
