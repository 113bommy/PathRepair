#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0, n, a;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    cnt += (i * a);
  }
  cout << cnt;
}
