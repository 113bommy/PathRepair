#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long i, hash[101] = {0}, x, ans = 0, s = 0, n;
  for (i = 0; i < 5; i++) {
    cin >> x;
    hash[x]++;
    ans += x;
  }
  s = ans;
  for (i = 0; i <= 100; i++) {
    if (hash[i] == 2) {
      s = min(s, ans - 2 * i);
    }
    if (hash[i] >= 3) s = min(s, ans - 3 * i);
  }
  cout << s;
  return 0;
}
