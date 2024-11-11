#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> s(n), b(m);
  for (auto &it : s) cin >> it;
  sort(s.begin(), s.end());
  for (auto &it : b) cin >> it;
  sort(b.begin(), b.end());
  if (s.front() >= b.back())
    cout << r << endl;
  else {
    int B = r % s.front();
    int S = r / 2;
    B += b.back() * S;
    cout << B << endl;
  }
  return 0;
}
