#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void test_cases() {
  string s;
  cin >> s;
  long long n = s.length();
  long long cntr = count(s.begin(), s.end(), 'R');
  long long cntp = count(s.begin(), s.end(), 'P'), cnts = n - (cntr + cntp);
  char c;
  if (max(cntr, max(cntp, cnts)) == cntr) {
    c = 'P';
  }
  if (max(cntr, max(cntp, cnts)) == cntp) {
    c = 'S';
  } else {
    c = 'R';
  }
  string ans(n, c);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    test_cases();
  }
}
