#include <bits/stdc++.h>
using namespace std;
int const inf = 0x7f7f7f7f;
long long const llinf = 0x7f7f7f7f7f7f7f7fll;
long double const eps = 1e-9;
using namespace std;
vector<long long> h1, rev1;
vector<unsigned long long> h2, rev2;
string s, s1;
int main() {
  long long n, curr, res = 0, cnt = 1, last;
  cin >> n;
  cin >> last;
  n--;
  while (n--) {
    cin >> curr;
    if (curr != last) {
      res += cnt * (cnt + 1) / 2;
      cnt = 1;
      last = curr;
    } else
      cnt++;
  }
  res += cnt * (cnt + 1) / 2;
  cout << res << endl;
  return 0;
}
