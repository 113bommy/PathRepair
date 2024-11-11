#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
const int C = 1001;
int main() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> points(n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &points[i].first.first, &points[i].first.second);
    points[i].second = i;
    points[i].first.first /= C;
  }
  sort((points).begin(), (points).end(),
       [](const pair<pair<int, int>, int> &a,
          const pair<pair<int, int>, int> &b) {
         return a.first.first < b.first.first ||
                (a.first.first == b.first.first &&
                 (a.first.first % 2 == 0 ? (a.first.second < b.first.second)
                                         : (a.first.second > b.first.second)));
       });
  for (auto i : points) {
    printf("%d ", i.second + 1);
  }
  puts("");
  return 0;
}
