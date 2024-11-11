#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  T = 1;
  for (int tc = 1; tc <= T; tc++) {
    int n;
    cin >> n;
    int ara[101] = {0};
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ara[x]++;
    }
    int even = 0;
    for (int i = 1; i <= 100; i++) {
      cnt += ara[i] / 4;
      ara[i] %= 4;
      if (ara[i] > 1) even++;
    }
    cnt += even / 2;
    cout << cnt << '\n';
  }
}
