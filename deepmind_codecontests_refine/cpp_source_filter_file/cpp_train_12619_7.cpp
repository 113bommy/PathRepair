#include <bits/stdc++.h>
using namespace std;
long long inf = (long long)1e9 + 5;
const long long MAX = 1000005;
long long cnt[2][MAX];
int main() {
  ios::sync_with_stdio(0);
  set<pair<long long, long long>> nums;
  long long n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    if (a == 1) {
      if (cnt[a][b] == 1) {
        if (cnt[a + 1][b - 1]) nums.erase({b, b - 1});
        if (cnt[a + 1][b]) nums.erase({b, b});
        if (cnt[a + 1][b + 1]) nums.erase({b, b + 1});
      } else {
        if (cnt[a + 1][b - 1]) nums.insert({b, b - 1});
        if (cnt[a + 1][b]) nums.insert({b, b});
        if (cnt[a + 1][b + 1]) nums.insert({b, b + 1});
      }
    } else {
      if (cnt[a][b]) {
        if (cnt[a - 1][b - 1]) nums.erase({b - 1, b});
        if (cnt[a - 1][b]) nums.erase({b, b});
        if (cnt[a - 1][b + 1]) nums.erase({b + 1, b});
      } else {
        if (cnt[a - 1][b - 1]) nums.insert({b - 1, b});
        if (cnt[a - 1][b]) nums.insert({b, b});
        if (cnt[a - 1][b + 1]) nums.insert({b + 1, b});
      }
    }
    cnt[a][b] ^= 1;
    if (nums.size())
      cout << "No\n";
    else
      cout << "Yes\n";
  }
  return 0;
}
