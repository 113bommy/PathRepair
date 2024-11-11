#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9 + 7;
const int N = 200007;
string s;
vector<int> a, b;
int n, t;
void add_carry() {
  int l = a.size();
  int i;
  for (i = l - 1; i >= 0; --i) {
    (a[i] += 1) %= 10;
    if (a[i] != 0) break;
  }
  if (i < 0 && a[0] == 0) a.insert(a.begin(), 1);
}
void solve() {
  cin >> n >> t;
  cin >> s;
  int p = s.find('.');
  string s1 = s.substr(0, p);
  string s2 = s.substr(p + 1);
  for (int i = 0; i < s1.size(); ++i) a.push_back(s1[i] - '0');
  for (int i = 0; i < s2.size(); ++i) b.push_back(s2[i] - '0');
  int carry = 0, last = 0;
  for (int i = 0; i < b.size(); ++i) {
    if (b[i] >= 5) {
      int j = i;
      while (t > 0 && j >= 0 && b[j] + carry >= 5) {
        b[j] = 0;
        carry = 1;
        --j;
        --t;
      }
      last = max(0, j);
      if (j >= 0)
        b[j] += carry;
      else
        add_carry();
      break;
    }
  }
  for (int i = 0; i < a.size(); ++i) cout << a[i];
  if (last > 0 || b[0] > 0) {
    cout << ".";
    for (int i = 0; i <= last; ++i) cout << b[i];
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  cout << fixed;
  solve();
  return 0;
}
