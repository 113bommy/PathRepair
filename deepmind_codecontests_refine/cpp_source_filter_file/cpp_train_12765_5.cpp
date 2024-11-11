#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > V1, V2;
int n, s;
int main() {
  while (~scanf("%d%d", &n, &s)) {
    V1.clear();
    V2.clear();
    long long sum1 = 0;
    long long sum2 = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long a, b, c;
      scanf("%d%d%d", &c, &a, &b);
      if (a > b) {
        sum1 += c;
        ans += c * a;
        V1.push_back(make_pair(a - b, c));
      } else {
        sum2 += c;
        ans += c * b;
        V2.push_back(make_pair(b - a, c));
      }
    }
    sum1 %= s;
    sum2 %= s;
    if (sum1 + sum2 > s) {
      cout << ans << endl;
      continue;
    } else {
      sort(V1.begin(), V1.end());
      sort(V2.begin(), V2.end());
      long long tmp1 = 0;
      long long tmp2 = 0;
      int len = V1.size();
      for (int i = 0; i < len; i++) {
        tmp1 += min(sum1, V1[i].second) * V1[i].first;
        sum1 -= min(sum1, V1[i].second);
      }
      len = V2.size();
      for (int i = 0; i < len; i++) {
        tmp2 += min(sum2, V2[i].second) * V2[i].first;
        sum2 -= min(sum2, V2[i].second);
      }
      cout << ans - min(tmp1, tmp2) << endl;
    }
  }
}
