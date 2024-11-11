#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
string s;
bool comp(int s1, int e1, int s2, int e2) {
  if (e1 - s1 != e2 - s2) return e1 - s1 > e2 - s2;
  for (int i = 0; i < e1 - s1 + 1; ++i) {
    if (s[i + s1] > s[i + s2])
      return true;
    else if (s[i + s1] < s[i + s2])
      return false;
  }
  return true;
}
int solve(int st, int end) {
  if (st == end) return 1;
  if ((end - st + 1) % 2 == 0) {
    if (s[st + (end - st) / 2 + 1] != '0') {
      if (comp(st, st + (end - st) / 2, st + (end - st) / 2 + 1, end))
        return solve(st, st + (end - st) / 2) +
               solve(st + (end - st) / 2 + 1, end);
    }
  }
  int len = end - st + 1;
  for (int i = st + len / 2 + 1; i <= end; ++i) {
    if (s[i] != '0') return solve(st, i - 1) + solve(i, end);
  }
  if (st != 0) {
    for (int i = st + 1; i <= end; ++i) {
      if (s[i] != '0') return 1 + solve(i, end);
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  cout << solve(0, ((long long)s.size()) - 1) << endl;
  return 0;
}
