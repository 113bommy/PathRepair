#include <bits/stdc++.h>
using namespace std;
bool f(vector<int> &v, int x) {
  sort(v.begin(), v.end());
  if (v.front() == x && v.back() == x) return true;
  if (x < v[1] + v[2]) {
    v[0] = x;
    return false;
  } else {
    v[0] = v[1] + v[2] - 1;
    return false;
  }
}
int main() {
  int x, y;
  cin >> x >> y;
  vector<int> v(3, y);
  long cnt = 0;
  while (!f(v, x)) cnt++;
  cout << cnt;
  return 0;
}
