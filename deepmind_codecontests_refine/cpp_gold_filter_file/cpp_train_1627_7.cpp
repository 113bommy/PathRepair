#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, S;
  scanf("%lld%lld", &N, &S);
  priority_queue<pair<long long, long long> > que;
  long long ans = 0, ssum = 0;
  for (int i = 1; i <= N; i++) {
    long long s, a, b;
    scanf("%lld%lld%lld", &s, &a, &b);
    que.push({b - a, s});
    ans += s * a;
    ssum += s;
  }
  if (ssum % S != 0) {
    que.push({0, S * (ssum / S + 1) - ssum});
  }
  vector<pair<long long, long long> > candi;
  while (!que.empty()) {
    candi.push_back(que.top());
    que.pop();
  }
  long long cost = 0, cnt = 0;
  for (int i = 0; i < candi.size(); i++) {
    cnt += candi[i].second;
    cost += candi[i].first * candi[i].second;
    if (cnt >= S) {
      if (candi[i].first >= 0) {
        long long remain = cnt % S;
        ans = max(ans, ans + cost - candi[i].first * remain);
        cnt = remain;
        cost = candi[i].first * remain;
      } else {
        long long remove = cnt - S;
        if (remove >= 0) {
          ans = max(ans, ans + cost - candi[i].first * remove);
        }
        break;
      }
    }
  }
  printf("%lld", ans);
  return 0;
}
