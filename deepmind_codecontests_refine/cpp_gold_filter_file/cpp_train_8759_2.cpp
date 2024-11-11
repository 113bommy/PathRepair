#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int n, i, minn = 1e3;
  cin >> n;
  cin >> s;
  for (i = 0; i <= n - 4; i++)
    minn = min(
        min(abs(s[i] - 'A'),
            min(abs(s[i] - 'Z') + 1, abs(s[i] - 'A') + 'Z' - 'A' + 1)) +
            min(abs(s[i + 1] - 'C'), min(abs(s[i + 1] - 'Z') + 3,
                                         abs(s[i + 1] - 'A') + 'Z' - 'C' + 1)) +
            min(abs(s[i + 2] - 'T'), min(abs(s[i + 2] - 'Z') + 'T' - 'A' + 1,
                                         abs(s[i + 2] - 'A') + 'Z' - 'T' + 1)) +
            min(abs(s[i + 3] - 'G'), min(abs(s[i + 3] - 'Z') + 'G' - 'A' + 1,
                                         abs(s[i + 3] - 'A') + 'Z' - 'G' + 1)),
        minn);
  cout << minn << '\n';
  return 0;
}
