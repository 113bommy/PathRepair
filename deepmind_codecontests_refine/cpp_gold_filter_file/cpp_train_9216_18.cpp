#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b >> c >> d;
  int cha1 = a - d;
  int cha2 = b - c;
  int cha3 = (a + b) - (c + d);
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    if ((i - cha1) >= 1 && (i - cha1) <= n && (i - cha2) >= 1 &&
        (i - cha2) <= n && (i - cha3) >= 1 && (i - cha3) <= n) {
      cnt += n;
    }
  }
  cout << cnt << endl;
}
