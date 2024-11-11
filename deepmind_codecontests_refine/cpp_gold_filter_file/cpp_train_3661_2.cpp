#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int tt = 1; tt <= tc; tt++) {
    long long n, q, x;
    cin >> n >> q;
    long long a[n], ma = -1;
    deque<long long> dq;
    pair<long long, long long> qu[q];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ma = max(ma, a[i]);
      dq.push_back(a[i]);
    }
    for (int i = 0; i < q; i++) {
      cin >> x;
      qu[i] = {x, i};
    }
    sort(qu, qu + q);
    long long cnt = 0, ind = 0;
    pair<long long, long long> ans[q];
    while (dq.front() != ma) {
      long long op1 = dq.front();
      dq.pop_front();
      long long op2 = dq.front();
      dq.pop_front();
      if (op1 > op2)
        dq.push_front(op1), dq.push_back(op2);
      else
        dq.push_front(op2), dq.push_back(op1);
      cnt++;
      while (ind < q && qu[ind].first == cnt)
        ans[qu[ind].second] = {op1, op2}, ind++;
    }
    vector<long long> v;
    dq.pop_front();
    for (int i = 0; i < n - 1; i++) {
      v.push_back(dq.front());
      dq.pop_front();
    }
    for (int i = ind; i < q; i++)
      ans[qu[i].second] = {ma, v[(qu[i].first - cnt + n - 1 - 1) % (n - 1)]};
    for (int i = 0; i < q; i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
