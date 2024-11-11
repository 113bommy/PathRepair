#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long n, b, c, d, ans, m, cnt, x, used[N], z;
vector<string> v, v1;
string s, s1;
set<char> st;
map<char, long long> mp;
char q, a[N];
vector<int> g[N];
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i < n; i++) {
    if (i + m > n) {
      for (long long j = n; j > i; j--) {
        if (a[j] == '1') {
          cnt++, i = j - 1;
          z = 1;
          break;
        }
      }
      if (z != 1) {
        cout << "-1";
        return 0;
      }
      cout << cnt;
      return 0;
    } else {
    }
    for (long long j = i + m; j > i; j--) {
      if (a[j] == '1') {
        cnt++, i = j - 1;
        z = 1;
        break;
      }
    }
    if (z != 1) {
      cout << "-1";
      return 0;
    }
    z = 0;
  }
  cout << cnt;
}
