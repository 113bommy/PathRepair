#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long cnt = 0;
  if (n + m < 5)
    cout << cnt;
  else {
    for (int i = 1; i <= n; i++) {
      cnt += (i % 5 + m) / 5;
    }
    cout << cnt;
  }
}
