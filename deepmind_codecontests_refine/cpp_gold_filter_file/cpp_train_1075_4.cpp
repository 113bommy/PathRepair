#include <bits/stdc++.h>
using namespace std;
class comp {
 public:
  bool operator()(const pair<long long int, long long int>& lhs,
                  const pair<long long int, long long int>& rhs) const {
    if (lhs.first > rhs.first)
      return 1;
    else if (lhs.first == rhs.first && lhs.second > rhs.second)
      return 1;
    return 0;
  }
};
int main() {
  long long int n;
  long long int count;
  cin >> n;
  vector<long long int> ip(n);
  vector<long long int> power2;
  for (long long int i = 0; pow(2, i) <= 2000; i++) power2.push_back(pow(2, i));
  vector<priority_queue<pair<long long int, long long int>,
                        vector<pair<long long int, long long int> >, comp> >
      vpq(n);
  for (long long int i = 1; i <= n; i++) {
    queue<pair<long long int, long long int> > bfs;
    vector<bool> vis(n);
    bfs.push(make_pair(i, 0));
    while (!bfs.empty()) {
      pair<long long int, long long int> temp = bfs.front();
      bfs.pop();
      if (vis[temp.first - 1] == 1) continue;
      vis[temp.first - 1] = 1;
      if (temp.first != i)
        vpq[i - 1].push(make_pair(temp.second, temp.first - 1));
      long long int lim = 0;
      while (power2[lim] + temp.first <= n) {
        bfs.push(make_pair(power2[lim] + temp.first, temp.second + 1));
        lim++;
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    cin >> ip[i];
  }
  for (long long int i = 1; i < n; i++) {
    count = 0;
    for (long long int j = 0; j < i; j++) {
      pair<long long int, long long int> temp = vpq[j].top();
      while (temp.second < i && !vpq[j].empty()) {
        vpq[j].pop();
        temp = vpq[j].top();
      }
      count += (long long int)(temp.first * ip[j]);
    }
    cout << count << "\n";
  }
  return 0;
}
