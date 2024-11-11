#include <bits/stdc++.h>
using namespace std;
bool sortfun(pair<int, int> &a, pair<int, int> &b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second >= b.second) return true;
  }
  return false;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> vec;
  vector<int> rank(51, 0);
  while (n--) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
  }
  sort(vec.begin(), vec.end(), sortfun);
  for (int i = vec.size() - 1, j = 1; i >= 0; i--) {
    if (i == vec.size() - 1)
      rank[j]++;
    else {
      if (vec[i].first == vec[i + 1].first &&
          vec[i].second == vec[i + 1].second)
        rank[j]++;
      else {
        j++;
        rank[j]++;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i < 50; i++) {
    sum += rank[i];
    if (k <= sum) {
      cout << rank[i];
      break;
    }
  }
  return 0;
}
