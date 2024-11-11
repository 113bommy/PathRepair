#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int nax = 1e5 + 10;
vector<int> tree(4 * nax);
int i, j, x, y, k, sp = 1, sum = 1;
map<long long, long long> s;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
class bitmask {
 public:
  void PowerSet(char *set, int set_size) {
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    for (counter = 0; counter < pow_set_size; counter++) {
      for (j = 0; j < set_size; j++) {
        if (counter & (1 << j)) cout << set[j];
      }
      cout << endl;
    }
  }
};
long long powerLL(long long x, long long n) {
  long long result = 1;
  while (n) {
    if (n & 1) result = result * x % MOD;
    n = n / 2;
    x = x * x % MOD;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, cnt = 0, cnt1 = 0;
  string s;
  cin >> s;
  for (i = 0; i <= s.length() / 2; i++) {
    if (i == s.length() - i - 1)
      cnt = 1;
    else if (s[i] != s[s.length() - i - 1] && cnt == 0) {
      s[s.length() - i - 1] = s[i];
      cnt = 1;
    } else if (s[i] != s[s.length() - i - 1]) {
      cout << "NO" << endl;
      cnt1 = 2;
      break;
    }
  }
  if (cnt1 != 2 && cnt == 1)
    cout << "YES" << endl;
  else if (cnt != 1 && cnt1 != 2)
    cout << "NO" << endl;
}
