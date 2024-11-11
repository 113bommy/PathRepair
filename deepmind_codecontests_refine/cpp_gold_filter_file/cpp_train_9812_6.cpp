#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[10], b[10];
vector<int> p;
bool square(int i, int j) {
  double len = sqrt((a[j].first - a[i].first) * (a[j].first - a[i].first) +
                    (a[j].second - a[i].second) * (a[j].second - a[i].second));
  for (int t = i + 1; t <= j; t++) {
    double tmp =
        sqrt((a[t].first - a[t - 1].first) * (a[t].first - a[t - 1].first) +
             (a[t].second - a[t - 1].second) * (a[t].second - a[t - 1].second));
    if (abs(len - tmp) > 0.000000001) return 0;
  }
  if (len * len > 0.000000001) {
    int x1 = a[i + 3].first - a[i].first, x2 = a[i + 1].first - a[i].first;
    int y1 = a[i + 3].second - a[i].second, y2 = a[i + 1].second - a[i].second;
    if (x1 * x2 + y1 * y2 == 0)
      return 1;
    else
      return 0;
  }
}
bool rect(int i, int j) {
  double len1 =
      sqrt((a[i].first - a[i + 1].first) * (a[i].first - a[i + 1].first) +
           (a[i].second - a[i + 1].second) * (a[i].second - a[i + 1].second));
  double len2 = sqrt((a[i + 2].first - a[i + 1].first) *
                         (a[i + 2].first - a[i + 1].first) +
                     (a[i + 2].second - a[i + 1].second) *
                         (a[i + 2].second - a[i + 1].second));
  double len3 = sqrt((a[i + 2].first - a[i + 3].first) *
                         (a[i + 2].first - a[i + 3].first) +
                     (a[i + 2].second - a[i + 3].second) *
                         (a[i + 2].second - a[i + 3].second));
  double len4 =
      sqrt((a[i + 3].first - a[i].first) * (a[i + 3].first - a[i].first) +
           (a[i + 3].second - a[i].second) * (a[i + 3].second - a[i].second));
  if (abs(len1 - len3) > 0.000000001 || abs(len2 - len4) > 0.000000001)
    return 0;
  else {
    int x1 = a[i + 3].first - a[i].first, x2 = a[i + 1].first - a[i].first;
    int y1 = a[i + 3].second - a[i].second, y2 = a[i + 1].second - a[i].second;
    if (x1 * x2 + y1 * y2 == 0)
      return 1;
    else
      return 0;
  }
}
bool check() {
  if (!square(0, 3)) return 0;
  if (!rect(4, 7)) return 0;
  return 1;
}
int main() {
  for (int i = 0; i < 8; i++) {
    cin >> a[i].first >> a[i].second;
    b[i] = a[i];
    p.push_back(i);
  }
  while (true) {
    if (check()) {
      cout << "YES\n";
      for (int i = 0; i <= 3; i++) cout << p[i] + 1 << " ";
      cout << endl;
      for (int i = 4; i <= 7; i++) cout << p[i] + 1 << " ";
      return 0;
    }
    if (!next_permutation(p.begin(), p.end())) break;
    for (int i = 0; i <= 7; i++) a[i] = b[p[i]];
  }
  cout << "NO";
  return 0;
}
