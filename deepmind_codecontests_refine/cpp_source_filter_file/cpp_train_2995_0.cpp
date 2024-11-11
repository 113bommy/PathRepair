#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> drop(n, 0);
  vector<pair<int, int> > arr(n, pair<int, int>(0, 0));
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i].first);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i].second);
  for (int i = 0; i < n; ++i) {
    int mini = 1 << 30;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j].first > arr[i].first) mini = min(mini, arr[j].second);
    }
    drop[i] = mini;
  }
  long long mini = 1LL << 40;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      if (arr[j].first <= arr[i].first) continue;
      if (drop[j + 1] == 1 << 30) continue;
      mini = min((long long)drop[j + 1] + (long long)arr[i].second +
                     (long long)arr[j].second,
                 mini);
    }
  }
  if (mini == 1LL << 40)
    cout << "-1" << endl;
  else
    cout << mini << endl;
}
