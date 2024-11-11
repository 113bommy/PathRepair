#include <bits/stdc++.h>
using namespace std;
long long t;
void test_cases(bool b) {
  if (b)
    cin >> t;
  else
    t = 1;
}
vector<pair<long long, long long> > solve();
int main() {
  long long n, c, s;
  cin >> n;
  long long ans[n];
  for (int i = 0; i < n; i++) {
    long long flag = 0, k, tc;
    cin >> c >> s;
    tc = c;
    if (c == 1)
      flag = s * s;
    else if (s <= c)
      flag = s;
    else {
      for (int j = 0; j < tc; j++) {
        k = s / c;
        if (k * c != s) {
          s--;
          c--;
        }
        flag += (k * k);
      }
    }
    ans[i] = flag;
  }
  for (long long i : ans) cout << i << endl;
  return 0;
}
