#include <bits/stdc++.h>
using namespace std;
pair<int, int> s[300010];
int n, k, l;
long long sum, now, ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &(s[i].first));
    s[i].second = i + 1;
  }
  scanf("%d", &k);
  sort(s, s + n);
  sum = 0;
  now = 0;
  for (int i = 0; i < k; i++) {
    now += ((long long)s[i].first * i) - sum;
    sum += s[i].first;
  }
  ans = now;
  l = 0;
  for (int p = k; p < n; p++) {
    now -= sum - (long long)s[p - k].first * k;
    sum -= s[p - k].first;
    sum += s[p].first;
    now += ((long long)s[p].first * k) - sum;
    if (now > ans) {
      ans = now;
      l = p - k + 1;
    }
  }
  for (int i = 0; i < k - 1; i++) {
    printf("%d ", s[i + l].second);
  }
  printf("%d\n", s[k + l - 1].second);
  return 0;
}
