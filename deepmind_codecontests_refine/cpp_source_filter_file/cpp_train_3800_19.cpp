#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  int j;
  int ANS = 0;
  for (int i = 1; i <= n; i++) {
    if (x % i == 0) {
      j = x / i;
      if (x <= n) ANS++;
    }
  }
  cout << ANS;
}
