#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
long long sum[N];
long long ans[N];
int num[N];
pair<pair<int, int>, int> Q[N];
int main() {
  int n, p;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  scanf("%d", &p);
  for (int i = 0; i < p; i++)
    scanf("%d%d", &Q[i].first.second, &Q[i].first.first), Q[i].second = i;
  sort(Q, Q + p);
  int pre_val = 0, T = 0;
  for (int i = 0; i < p; i++) {
    if (Q[i].first.first != pre_val && T < 200) {
      T++;
      pre_val = Q[i].first.first;
      for (int j = 1; j <= n; j++) {
        sum[j] = num[j];
        if (j > Q[i].first.first) sum[j] += sum[j - Q[i].first.first];
      }
    }
    if (Q[i].first.first == pre_val) {
      ans[Q[i].second] = sum[n - (n - Q[i].first.second) % Q[i].first.first];
      if (Q[i].first.second > Q[i].first.first)
        ans[Q[i].second] -= sum[Q[i].first.second - Q[i].first.first];
    } else {
      for (int j = Q[i].first.second; j <= n; j += Q[i].first.first)
        ans[Q[i].second] += num[j];
    }
  }
  for (int i = 0; i < p; i++) printf("%I64d\n", ans[i]);
  return 0;
}
