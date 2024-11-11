#include <bits/stdc++.h>
using namespace std;
string convertTostr(int x) {
  stringstream ss;
  ss << x;
  string st;
  st = ss.str();
  return st;
}
unsigned long long convertToint(string y) {
  unsigned long long num;
  stringstream ss(y);
  ss >> num;
  return num;
}
unsigned long long fpow(unsigned long long b, unsigned long long p,
                        unsigned long long m) {
  if (p == 0) return 1;
  if (p == 1) return b % m;
  unsigned long long res = fpow(b, p / 2, m) % m;
  res = (res * res) % m;
  if (p % 2 != 0) res = (res * (b % m)) % m;
  return res;
}
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int> > vec;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
  }
  int cnt = 0;
  for (int i = 0; i < n - 3; i++) {
    int curX = vec[i].first, curY = vec[i].second;
    int nX = vec[i + 1].first, nY = vec[i + 1].second;
    int aX = vec[i + 2].first, aY = vec[i + 2].second;
    if ((nX > curX && aY > nY) || (nX < curX && aY < nY) ||
        (nY > curY && aX < nX) || (nY < curY && aX > nX))
      cnt++;
  }
  cout << cnt;
  return 0;
}
