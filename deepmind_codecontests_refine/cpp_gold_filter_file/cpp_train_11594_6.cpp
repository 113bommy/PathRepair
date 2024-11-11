#include <bits/stdc++.h>
using namespace std;
vector<int> a;
long long sum[1000];
vector<int> res;
int main() {
  int s, k;
  scanf("%d%d", &s, &k);
  a.push_back(0);
  a.push_back(1);
  sum[0] = 0;
  sum[1] = 1;
  while (1) {
    int cur = a.size();
    long long now;
    if (cur > k)
      now = sum[cur - 1] - sum[cur - k - 1];
    else
      now = sum[cur - 1];
    sum[cur] = sum[cur - 1] + now;
    if (now <= s)
      a.push_back(now);
    else
      break;
  }
  a.resize((unique(a.begin(), a.end())) - a.begin());
  reverse(a.begin(), a.end());
  for (int i = (0); i < (a.size()); ++i) {
    if (s >= a[i]) {
      res.push_back(a[i]);
      s -= a[i];
    }
  }
  printf("%d\n", res.size());
  for (int i = (0); i < (res.size()); ++i) {
    if (i) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}
