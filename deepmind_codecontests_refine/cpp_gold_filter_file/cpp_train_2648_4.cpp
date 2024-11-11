#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e2 + 5, INF = (int)1e9;
const long double EPS = 1e-9;
pair<int, int> a[7];
int main() {
  for (int i = 0; i < 4; i++) cin >> a[i].first >> a[i].second;
  if (a[0].first > a[3].second && a[1].second > a[2].first &&
      a[0].first > a[2].second && a[1].second > a[3].first) {
    cout << "Team 1\n";
    return 0;
  }
  swap(a[0], a[1]);
  if (a[0].first > a[3].second && a[1].second > a[2].first &&
      a[0].first > a[2].second && a[1].second > a[3].first) {
    cout << "Team 1\n";
    return 0;
  }
  swap(a[0], a[1]);
  if (((a[0].first < a[3].second && a[1].second < a[2].first) ||
       (a[0].first < a[2].second && a[1].second < a[3].first)) &&
      ((a[1].first < a[3].second && a[0].second < a[2].first) ||
       (a[1].first < a[2].second && a[0].second < a[3].first))) {
    cout << "Team 2\n";
    return 0;
  }
  cout << "Draw\n";
  return 0;
}
