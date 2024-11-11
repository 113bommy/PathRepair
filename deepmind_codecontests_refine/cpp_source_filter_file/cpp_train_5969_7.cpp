#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1677721600")
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < (int)t; k++) {
    long long n, m;
    std::pair<long long, long long> a1, a2;
    cin >> n >> m >> a1.first >> a1.second >> a2.first >> a2.second;
    long long leftd = abs(a1.first - a2.first);
    long long upd = abs(a1.second - a2.second);
    long long answer = 2 * leftd * upd;
    if (leftd * 2 > n && upd * 2 <= n) {
      answer += ((leftd * 2 - n) * (m - 2 * upd));
    }
    if (upd * 2 > m && leftd * 2 <= m) {
      answer += ((upd * 2 - m) * (n - 2 * leftd));
    }
    if (2 * leftd > n && 2 * upd > m)
      answer -= ((2 * leftd - n) * (2 * upd - m));
    cout << answer << endl;
  }
  return 0;
}
