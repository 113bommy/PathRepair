#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[5];
vector<pair<int, int> > res;
int main() {
  for (int i = 1; i <= 3; i++) scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + 4);
  res.clear();
  if (a[1].second > a[2].second && a[1].second >= a[3].second) {
    if (a[2].second > a[3].second) {
      for (int i = a[2].first; i <= a[3].first; i++)
        res.push_back(pair<int, int>(i, a[2].second));
      for (int i = a[2].second - 1; i >= a[3].second; i--)
        res.push_back(pair<int, int>(a[3].first, i));
    } else {
      for (int i = a[2].first; i <= a[3].first; i++)
        res.push_back(pair<int, int>(i, a[3].second));
      for (int i = a[3].second - 1; i >= a[2].second; i--)
        res.push_back(pair<int, int>(a[2].first, i));
    }
    int y = max(a[2].second, a[3].second);
    for (int i = a[1].first; i < a[2].first; i++)
      res.push_back(pair<int, int>(i, a[1].second));
    for (int i = a[1].second; i >= y + 1; i--)
      res.push_back(pair<int, int>(a[2].first, i));
  } else if (a[3].second >= a[1].second && a[3].second > a[2].second) {
    if (a[1].second > a[2].second) {
      for (int i = a[1].first; i <= a[2].first; i++)
        res.push_back(pair<int, int>(i, a[1].second));
      for (int i = a[1].second - 1; i >= a[2].second; i--)
        res.push_back(pair<int, int>(a[2].first, i));
    } else {
      for (int i = a[1].first; i <= a[2].first; i++)
        res.push_back(pair<int, int>(i, a[2].second));
      for (int i = a[2].second - 1; i >= a[1].second; i--)
        res.push_back(pair<int, int>(a[1].first, i));
    }
    int y = max(a[1].second, a[2].second);
    for (int i = a[2].first; i < a[3].first; i++)
      res.push_back(pair<int, int>(i, a[3].second));
    for (int i = a[3].second; i >= y + 1; i--)
      res.push_back(pair<int, int>(a[2].first, i));
  } else {
    if (a[1].second > a[3].second) {
      for (int i = a[1].first; i <= a[3].first; i++)
        res.push_back(pair<int, int>(i, a[1].second));
      for (int i = a[1].second - 1; i >= a[3].second; i--)
        res.push_back(pair<int, int>(a[3].first, i));
    } else {
      for (int i = a[1].first; i <= a[3].first; i++)
        res.push_back(pair<int, int>(i, a[3].second));
      for (int i = a[3].second - 1; i >= a[1].second; i--)
        res.push_back(pair<int, int>(a[1].first, i));
    }
    int y = max(a[1].second, a[3].second);
    for (int i = a[2].second; i >= y + 1; i--)
      res.push_back(pair<int, int>(a[2].first, i));
  }
  printf("%d\n", (int)res.size());
  for (auto x : res) printf("%d %d\n", x.first, x.second);
}
