#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    s.push_back(make_pair(a - b, i));
  }
  int s1 = 0, s2 = 0;
  for (const auto &x : s) {
    if (x.first < 0)
      s1 += x.first;
    else
      s2 += x.first;
  }
  sort(s.begin(), s.end());
  int minn = (*s.begin()).first, maxx = (*(s.end() - 1)).first;
  if (minn < 0) s2 -= minn;
  if (maxx > 0) s1 -= maxx;
  if (minn * maxx >= 0)
    cout << 0 << endl;
  else if (abs(s1) < abs(s2))
    cout << (*s.begin()).second << endl;
  else
    cout << (*(s.end() - 1)).second << endl;
  return 0;
}
