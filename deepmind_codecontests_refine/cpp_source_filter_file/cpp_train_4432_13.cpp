#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long n = s.length();
  long long st_row[] = {4, 5, 6, 3, 2, 1};
  long long i, m = 0, ans = 0;
  for (--n, i = 0; i < n; i++) {
    m = m * 10 + (s[i] - '0');
  }
  ans = (m / 4 - (m % 4 == 0)) * 17 + (m % 4 % 2 == 0 ? 7 : 0) +
        st_row[s[n] - 'a'];
  cout << ans;
  return 0;
}
