#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long l[n], d[n];
  vector<pair<long long, long long> > v;
  multiset<pair<long long, long long> > st;
  long long k = 100005;
  long long visited[k];
  memset(visited, 0, sizeof(visited));
  long long total = 0;
  for (long long i = 0; i < n; i++) cin >> l[i];
  for (long long i = 0; i < n; i++) cin >> d[i];
  for (long long i = 0; i < n; i++) {
    v.push_back(make_pair(l[i], d[i]));
    st.insert(make_pair(-d[i], l[i]));
    total += d[i];
  }
  sort(v.begin(), v.end());
  long long ans = 1000000000;
  for (long long i = n - 1; i >= 0; i--) {
    long long cur = v[i].first;
    visited[cur] = 1;
    long long ind = i;
    long long sm = 0;
    while (cur == v[ind].first) {
      sm += v[ind].second;
      ind--;
      if (ind == -1) break;
    }
    long long num = i - ind;
    long long curNum = 0;
    vector<pair<long long, long long> > toRemove;
    for (auto elem : st) {
      if (curNum == num - 1) break;
      if (visited[elem.second] == 1) {
        toRemove.push_back(elem);
        continue;
      }
      sm -= elem.first;
      curNum++;
    }
    ans = min(ans, total - sm);
    for (long long j = 0; j < toRemove.size(); j++) {
      st.erase(toRemove[j]);
    }
    i = ind + 1;
  }
  cout << ans;
  return 0;
}
