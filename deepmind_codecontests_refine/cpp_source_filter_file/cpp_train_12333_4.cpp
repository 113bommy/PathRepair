#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> subject[100010];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
int main() {
  int n, r, avg;
  while (cin >> n >> r >> avg) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
      cin >> subject[i].first >> subject[i].second;
      total += subject[i].first;
    }
    long long point = avg * n - total;
    sort(subject, subject + n, cmp);
    long long ans = 0;
    long long pos = 0;
    while (point > 0) {
      if (subject[pos].first < r) {
        if (point > (r - subject[pos].first)) {
          point -= (r - subject[pos].first);
          ans += (r - subject[pos].first) * subject[pos].second;
        } else {
          ans += point * subject[pos].second;
          point = 0;
        }
      }
      pos++;
    }
    cout << ans << endl;
  }
  return 0;
}
