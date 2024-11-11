#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
string s;
vector<int> a, b;
int n, st, dr, sol, mid, pos;
bool check(int val) {
  int i, j, dist;
  j = 0;
  for (i = 0; i < (int)a.size(); i++) {
    if (a[i] - b[j] > val) return 0;
    pos = a[i];
    if (a[i] <= b[j])
      pos += val;
    else {
      dist = a[i] - b[j];
      pos += max((val - dist) / 2, val - 2 * dist);
    }
    while (j < b.size() && b[j] <= pos) j++;
    if (j == b.size()) return 1;
  }
  return j == b.size();
}
int main() {
  int i;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  cin >> s;
  for (i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'P') a.push_back(i);
    if (s[i] == '*') b.push_back(i);
  }
  st = 1;
  dr = 2 * n;
  while (st <= dr) {
    mid = (st + dr) / 2;
    if (check(mid)) {
      sol = mid;
      dr = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  cout << sol;
  return 0;
}
