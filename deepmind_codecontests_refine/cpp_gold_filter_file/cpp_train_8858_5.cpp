#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  bool nd = 0;
  int n, a, b, i, vacancy = 0, counter[1001] = {};
  stack<pair<int, int>> vacant;
  vector<int> graph[1001] = {};
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> a >> b;
    counter[min(a, b)]++;
    if (max(a, b) != n) nd = 1;
  }
  if (counter[n]) nd = 1;
  for (i = n - 1; i; i--) {
    if (counter[i]) {
      vacancy += counter[i] - 1;
      if (counter[i] - 1)
        vacant.push(make_pair(i, counter[i] - 1));
      else
        graph[n].push_back(i);
    }
    if (!counter[i]) {
      if (vacancy) {
        auto t = vacant.top();
        vacant.pop();
        graph[t.first].push_back(i);
        t.first = i;
        t.second--;
        vacancy--;
        if (t.second)
          vacant.push(t);
        else
          graph[n].push_back(i);
      } else
        break;
    }
  }
  if (i || nd)
    cout << "NO\n";
  else {
    while (!vacant.empty()) {
      auto t = vacant.top();
      vacant.pop();
      vacancy--;
      graph[n].push_back(t.first);
    }
    cout << "YES\n";
    for (i = 1; i <= n; i++)
      for (auto j : graph[i]) cout << i << " " << j << endl;
  }
}
