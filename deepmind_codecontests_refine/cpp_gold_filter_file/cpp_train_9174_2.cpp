#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k, c, pre_c, s;
  cin >> n >> m >> k >> pre_c;
  long long first_c = pre_c;
  multiset<long long> l;
  if (n == 1) {
    cout << 1 << endl;
    ;
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> c;
    l.insert(c - pre_c - 1);
    pre_c = c;
  }
  s = c - first_c + 1;
  for (auto iter = l.rbegin(); iter != l.rend() && k > 1; iter++) {
    k--;
    s -= *iter;
  }
  cout << s << endl;
}
int main() {
  int n = 1;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
