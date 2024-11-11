#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
map<int, pair<bool, priority_queue<int>>> pbs;
int n;
int main() {
  cin >> n;
  int a[maxn];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pbs[a[i]].first = true;
  }
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    pbs[a[i]].second.push(t);
  }
  priority_queue<int> buf;
  long long sum = 0;
  long long ans = 0;
  for (auto i : pbs) {
    while (!i.second.second.empty()) {
      int tmp = i.second.second.top();
      i.second.second.pop();
      sum += tmp;
      buf.push(tmp);
    }
    if (!buf.empty()) {
      sum -= buf.top();
      ans += sum;
      buf.pop();
    }
    if (!buf.empty()) {
      pbs[i.first + 1].first = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
