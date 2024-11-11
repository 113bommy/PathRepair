#include <bits/stdc++.h>
using namespace std;
long long q, n, ans1, ans2;
int main() {
  cin >> q;
  while (q--) {
    ans1 = 0;
    ans2 = 0;
    cin >> n;
    vector<pair<long long, long long> > cnt(n + 1);
    vector<long long> matcnt[n + 1];
    for (int i = 1; i <= n; i++) cnt[i].first = 0, cnt[i].second = 0;
    for (int i = 0; i < n; i++) {
      long long a;
      bool f;
      cin >> a >> f;
      cnt[a].first++;
      if (f) cnt[a].second++;
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[i].first == 0) continue;
      matcnt[cnt[i].first].push_back(cnt[i].second);
    }
    priority_queue<long long> pq;
    for (long long i = n; i > 0; i--) {
      if (matcnt[i].size() == 0 && pq.empty()) continue;
      long long sez = matcnt[i].size();
      for (int j = 0; j < sez; j++) pq.push(matcnt[i][j]);
      ans1 += min(pq.top(), i);
      ans2 += i;
      pq.pop();
    }
    cout << ans2 << " " << ans1 << "\n";
    for (int i = 0; i <= n; i++) matcnt[i].clear();
    while (!pq.empty()) pq.pop();
  }
}
