#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b;
  cin >> a >> b;
  int cnt = 0;
  while (a && b) {
    if (a >= b) {
      cnt += a / b;
      a %= b;
    } else {
      cnt += b / a;
      b %= a;
    }
  }
  cout << cnt << endl;
  return 0;
}
