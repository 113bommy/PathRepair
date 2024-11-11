#include <bits/stdc++.h>
using namespace std;
int mod_fact(int n, int x) {
  int out = 1;
  for (int i = n; i >= 2; i--) {
    out *= i;
    out %= x;
  }
  return (out);
}
int main() {
  int n;
  cin >> n;
  vector<int> all[n];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    all[a].push_back(b);
    all[b].push_back(a);
  }
  long long out = n;
  for (int i = 0; i < n; i++) {
    out *= mod_fact(all[i].size(), 998244353);
    out %= 998244353;
  }
  cout << out;
}
