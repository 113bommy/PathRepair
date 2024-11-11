#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e18;
long long m_inf = INT_MIN;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(9);
  map<long long, pair<long long, long long> > m = {
      {1, {1, 1}}, {2, {1, 2}}, {3, {1, 3}}, {4, {2, 1}}, {5, {2, 2}},
      {6, {2, 3}}, {7, {3, 1}}, {8, {3, 2}}, {9, {3, 3}}, {0, {4, 2}}};
  long long n;
  cin >> n;
  string str;
  cin >> str;
  for (long long i = 0; i <= 9; i++) {
    bool flag = true;
    if (str[0] == i + '0') continue;
    pair<long long, long long> curr = m[i];
    for (long long i = 1; i < n; i++) {
      pair<long long, long long> p = m[str[i - 1] - '0'];
      pair<long long, long long> nxt = m[str[i] - '0'];
      pair<long long, long long> del = {nxt.first - p.first,
                                        nxt.second - p.second};
      curr.first += del.first;
      curr.second += del.second;
      if (curr.first > 4 || (curr.first == 4 && curr.second != 2) ||
          curr.second > 3 || curr.first < 1 || curr.second < 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
