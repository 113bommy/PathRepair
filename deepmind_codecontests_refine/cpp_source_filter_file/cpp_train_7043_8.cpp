#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, l;
  cin >> w >> l;
  int arr[w];
  for (int i = 1; i <= w - 1; i++) cin >> arr[i];
  int idx, t, total = 0;
  deque<pair<int, int> > queries;
  for (idx = w - 1, t = l; t > 0; t--, idx--)
    if (arr[idx]) queries.push_back({arr[idx], idx});
  while (idx > l) {
    while (!queries.empty() && queries.front().second - idx > l)
      queries.pop_front();
    int tot = 0;
    while (arr[idx]) {
      if (queries.empty()) break;
      if (queries.front().first <= arr[idx]) {
        arr[idx] -= queries.front().first;
        tot += queries.front().first;
        queries.pop_front();
      } else {
        queries.front().first -= arr[idx];
        tot += arr[idx];
        arr[idx] = 0;
      }
    }
    if (tot) queries.push_back({tot, idx});
    idx--;
  }
  int ans = 0;
  for (auto i : queries) ans += i.first;
  cout << ans << endl;
}
