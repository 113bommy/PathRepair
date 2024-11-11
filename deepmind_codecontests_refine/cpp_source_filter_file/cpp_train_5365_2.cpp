#include <bits/stdc++.h>
using namespace std;
const int M = 2e3 + 5;
map<pair<int, int>, int> mp;
pair<int, int> A[M];
int main() {
  int n;
  scanf("%d", &n);
  for (int j = 1; j <= n; j++) {
    scanf("%d%d", &A[j].first, &A[j].second);
  }
  for (int j = 1; j <= n; j++) {
    for (int k = j + 1; k <= n; k++) {
      pair<int, int> now;
      now.first = A[k].second - A[j].second,
      now.second = A[k].first - A[j].first;
      if (now.first < 0 && now.second < 0)
        now.first = -now.first, now.second = -now.second;
      if (now.first > 0 && now.second < 0)
        now.first = -now.first, now.second = -now.second;
      mp[now]++;
    }
  }
  long long ans = 0;
  for (int j = 1; j <= n; j++) {
    for (int k = j + 1; k <= n; k++) {
      pair<int, int> now;
      now.first = A[k].second - A[j].second,
      now.second = A[k].first - A[j].first;
      if (now.first < 0 && now.second < 0)
        now.first = -now.first, now.second = -now.second;
      if (now.first > 0 && now.second < 0)
        now.first = -now.first, now.second = -now.second;
      ans += mp[now] - 1;
    }
  }
  cout << ans / 4 << endl;
  return 0;
}
