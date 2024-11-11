#include <bits/stdc++.h>
using namespace std;
long long o[100010];
long long pw[60];
priority_queue<long long> pq;
vector<long long> k[100010];
int main() {
  long long i, j, n;
  long long cnt;
  long long sz;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &o[i]);
    if ((o[i] & (-o[i])) != o[i])
      pq.push(o[i]);
    else {
      long long tmp = o[i];
      cnt = 0;
      while (tmp > 1) {
        tmp >>= 1;
        cnt++;
      }
      pw[cnt]++;
    }
  }
  sz = pw[0];
  for (i = 0; i < sz; i++) k[i].push_back(1);
  for (i = 1; i < 60; i++) {
    if (pw[i] == 0) continue;
    cnt = 0;
    while (pw[i] > 0 && cnt < sz) {
      if (k[cnt].back() * 2 == ((long long)1 << i))
        k[cnt].push_back((long long)1 << i);
      else
        break;
      cnt++;
      pw[i]--;
    }
    while (pw[i] > 0) {
      pq.push((long long)1 << i);
      pw[i]--;
    }
  }
  long long ss = pq.size();
  if (pq.size() > 0) {
    for (i = 0; i < sz; i++) {
      long long tmp = pq.top();
      pq.pop();
      if (tmp <= k[i].back() * 2)
        k[i].push_back(tmp);
      else {
        printf("-1\n");
        return 0;
      }
      if (pq.size() == 0) break;
    }
    if (pq.size()) {
      printf("-1\n");
      return 0;
    }
  }
  vector<long long> ans;
  long long all = sz - ss;
  ans.push_back(sz);
  for (i = sz - 1; i >= 0; i--) {
    if (all >= k[i].size() + 1) {
      for (auto v : k[i]) pq.push(v);
      long long ff = pq.size();
      for (j = ss; j < sz; j++) {
        long long tmp = pq.top();
        if (tmp <= k[j].back() * 2)
          k[j].push_back(tmp);
        else
          break;
        pq.pop();
        if (pq.size() == 0) break;
      }
      if (pq.size() > 0)
        break;
      else
        ss += ff, all -= ff + 1;
      ans.push_back(i);
    } else
      break;
  }
  for (i = ans.size() - 1; i >= 0; i--) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
