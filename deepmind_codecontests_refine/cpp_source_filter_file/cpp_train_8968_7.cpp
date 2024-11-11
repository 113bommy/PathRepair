#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
long long kol, sum, id, ans;
string s;
vector<long long> a;
int main() {
  cin >> s;
  ans = 0;
  sum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'v') {
      id += 1;
      if (i == s.size() - 1) {
        sum += id - 1;
      }
    } else {
      if (id != 0) {
        sum += id - 1;
        id = 0;
      }
      a.push_back(sum);
      kol += 1;
    }
  }
  if (a.size() == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i <= kol; i++) {
    ans += a[i] * (sum - a[i]);
  }
  cout << ans;
  return 0;
}
