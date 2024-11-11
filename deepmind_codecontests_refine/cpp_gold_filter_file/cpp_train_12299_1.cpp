#include <bits/stdc++.h>
using namespace std;
int n;
long long int c;
long long int d;
vector<pair<int, char> > v;
char buf[4];
long long int dp[100002];
int main() {
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    scanf("%s", buf);
    v.push_back(make_pair(num, buf[0]));
  }
  {
    int t;
    scanf("%d", &t);
    v.push_back(make_pair(t, '?'));
  }
  char af = '?';
  int op = n;
  long long int ans = (long long int)(d)*n;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (af != v[i].second) {
      af = v[i].second;
      op = i + 1;
    }
    long long int lef = v[i].first;
    long long int rig = v[op].first;
    dp[i] = dp[op];
    dp[i] += c * (rig - lef);
    for (int j = i + 1; j < op; j++) {
      dp[i] += min(c * (rig - v[j].first), d);
    }
    ans = min(ans, dp[i] + i * d);
  }
  printf("%lld\n", ans);
  return 0;
}
