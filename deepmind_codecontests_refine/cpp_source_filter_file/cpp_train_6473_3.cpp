#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void start();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  start();
  return 0;
}
void start() {
  int n;
  cin >> n;
  vector<int> s(n);
  int im = 0, pa = 0;
  for (size_t i = 0; i < n; ++i) {
    cin >> s[i];
    (s[i] % 2) ? ++im : ++pa;
  }
  (s[0] % 2) ? cout << pa << '\n' : cout << im << '\n';
}
