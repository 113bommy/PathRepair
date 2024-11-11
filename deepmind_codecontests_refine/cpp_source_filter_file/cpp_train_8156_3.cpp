#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > otr;
inline bool operator<(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first && a.second < b.second) return true;
  return false;
}
int main() {
  int x, y, a, b;
  scanf(" %d %d %d %d", &x, &y, &a, &b);
  for (int j = b; j <= y; ++j) {
    for (int i = a + 1; i <= x; ++i) {
      if (i > j) otr.push_back(std::pair<int, int>(i, j));
    }
  }
  sort(otr.begin(), otr.end());
  int size = otr.size();
  printf("%d\n", size);
  for (int i = 0; i < size; ++i) printf("%d %d\n", otr[i].first, otr[i].second);
  return 0;
}
