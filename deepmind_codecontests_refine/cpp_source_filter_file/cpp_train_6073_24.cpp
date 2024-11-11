#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const int LIM = 1e7 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y;
int is_com[LIM];
vector<int> pr;
void sieve() {
  is_com[1] = 1;
  for (int i = 2; i < LIM; i++) {
    if (!is_com[i]) {
      pr.push_back(i);
      for (int j = i + i; j < LIM; j += i) {
        is_com[j] = 1;
      }
    }
  }
}
int getrev(int i) {
  vector<int> v;
  while (i) v.push_back(i % 10), i /= 10;
  int ans = 0;
  for (auto &it : v) ans *= 10, ans += it;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve();
  vector<int> fans;
  for (auto &it : pr) {
    int j = getrev(it);
    if (j != it && !is_com[j]) fans.push_back(it);
  }
  cin >> n;
  cout << fans[n] << "\n";
  return 0;
}
