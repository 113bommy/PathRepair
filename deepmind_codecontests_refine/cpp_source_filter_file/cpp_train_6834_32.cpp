#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int tab[MAXN];
long long solve(int k) {
  if (k > 36) return -1;
  string s((k + 1) / 2, '8');
  if (k % 2 == 1) s.back() = '0';
  return stoll(s);
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << solve(k);
}
