#include <bits/stdc++.h>
using namespace std;
long long q, cnt[5];
string s;
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cout << fixed;
  cout << setprecision(15);
  srand(time(NULL));
  cin >> q;
  while (q--) {
    memset(cnt, 0, sizeof cnt);
    cin >> s;
    long long n = s.size();
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'L') cnt[0]++;
      if (s[i] == 'R') cnt[1]++;
      if (s[i] == 'U') cnt[2]++;
      if (s[i] == 'D') cnt[3]++;
    }
    cnt[0] = min(cnt[0], cnt[1]);
    cnt[1] = cnt[0];
    cnt[2] = min(cnt[2], cnt[3]);
    cnt[3] = cnt[2];
    long long cur = 0, sum = 0;
    for (long long i = 0; i < 4; i++) cur += (cnt[i] > 0), sum += cnt[i];
    if (cur == 4) {
      cout << sum << "\n";
      for (long long i = 0; i < cnt[0]; i++) cout << "L";
      for (long long i = 0; i < cnt[1]; i++) cout << "R";
      for (long long i = 0; i < cnt[2]; i++) cout << "U";
      for (long long i = 0; i < cnt[3]; i++) cout << "D";
      cout << "\n";
    } else if (cur == 2) {
      cout << 2 << "\n";
      if (cnt[0] > 0)
        cout << "LR"
             << "\n";
      else
        cout << "UD"
             << "\n";
    } else {
      assert(cur == 0);
      cout << 0 << "\n";
      puts("");
    }
  }
  return 0;
}
