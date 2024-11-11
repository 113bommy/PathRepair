#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T& x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T& x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 1e2 + 17;
string s;
bool ok[maxn];
int toint(string s) {
  int ans = 0, z = 1;
  while (s.size()) ans += z * (s.back() - '0'), s.pop_back(), z *= 10;
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  srand(time(0));
  cin >> s;
  ok['1'] = ok['6'] = ok['8'] = ok['9'] = 1;
  set<char> mis({'1', '6', '8', '9'});
  for (int i = 0; i < 4; i++) {
    swap(s[i], s[s.find_first_of(*mis.begin())]);
    mis.erase(*mis.begin());
  }
  while (true) {
    random_shuffle(s.begin(), s.begin() + 4);
    if (toint(s) % 7 == 0) return cout << s << '\n', 0;
  }
  return 0;
}
