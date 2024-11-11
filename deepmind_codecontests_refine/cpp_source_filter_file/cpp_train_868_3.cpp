#include <bits/stdc++.h>
using namespace std;
int mon[12] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
inline int num(int m, int d, int h, int mm, int s) {
  d += mon[m - 1];
  h += d * 24;
  m += h * 60;
  s += mm * 60;
  return s;
}
vector<int> res;
int main() {
  for (int i = 1; i < 12; i++) {
    mon[i] += mon[i - 1];
  }
  int n, nm, k = 0;
  scanf("%d %d", &n, &nm);
  int y, m, d, h, mm, s;
  while (~scanf("%d-%d-%d %d:%d:%d: ", &y, &m, &d, &h, &mm, &s)) {
    string ss;
    getline(cin, ss);
    int x = num(m, d, h, mm, s);
    res.push_back(x);
    while (k < (int)res.size() && res[k] <= x - n) k++;
    if (res.size() - k >= nm) {
      printf("2012-%02d-%02d %02d:%02d:%02d", m, d, h, mm, s);
      return 0;
    }
  }
  cout << -1;
}
