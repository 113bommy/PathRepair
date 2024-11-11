#include <bits/stdc++.h>
using namespace std;
bool compare(pair<double, int> p1, pair<double, int> p2) {
  return p1.first > p2.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  vector<pair<double, int>> participants(n);
  int a, b;
  for (size_t i = 0; i < n; i++) {
    cin >> a >> b;
    participants[i] = make_pair(max(a * t1 * (100 - k) / 100.0 + b * t2,
                                    b * t1 * (100 - k) / 100.0 + a * t2),
                                i + 1);
  }
  stable_sort(participants.begin(), participants.end(), compare);
  for (size_t i = 0; i < n; i++)
    cout << participants[i].second << " " << fixed << setprecision(2)
         << participants[i].first << endl;
}
