#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > temp;
vector<pair<int, int> > ans;
int main() {
  int i, j, n, s, no1, no, id, id1, x;
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> x;
    pq.push(make_pair(x, i));
  }
  while (pq.size()) {
    id = pq.top().second;
    no = pq.top().first;
    pq.pop();
    while (pq.size() && no > 0) {
      id1 = pq.top().second;
      no1 = pq.top().first;
      pq.pop();
      no--;
      no1--;
      if (no1) temp.push_back(make_pair(no1, id1));
      ans.push_back(make_pair(id, id1));
    }
    if (no != 0) {
      cout << "No";
      return 0;
    }
    for (i = 0; i < temp.size(); i++)
      pq.push(make_pair(temp[i].first, temp[i].second));
    temp.clear();
  }
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
