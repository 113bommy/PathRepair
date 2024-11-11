#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = 1001001001;
const int MAX = 1e5 + 5;
vector<int> get(const string &s) {
  int sz = s.size();
  vector<int> ret(sz + 1, 0);
  for (int i = 0; i < sz; i++) {
    ret[i + 1] = s[i] - 'a';
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> a = get(s), b = get(t);
  for (int i = n; i - 1 >= 0; i--) {
    a[i] += b[i];
    if (a[i] > 26) {
      a[i] -= 26;
      a[i - 1]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    if (a[i] % 2 == 1) {
      a[i + 1] += 26;
    }
    a[i] /= 2;
  }
  for (int i = 1; i <= n; i++) {
    cout << (char)('a' + a[i]);
  }
}
