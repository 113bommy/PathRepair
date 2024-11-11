#include <bits/stdc++.h>
using namespace std;
const int WMAX = 1e9;
bool ch[100005];
vector<int> prime;
vector<pair<int, pair<int, int> > > ans;
void sieve() {
  memset(ch, true, sizeof(ch));
  ch[0] = false;
  ch[1] = false;
  for (int i = 2; i <= 100000; i++) {
    if (ch[i]) {
      prime.push_back(i);
      for (long long j = 1LL * i * i; j <= 100000; j += i) {
        ch[j] = false;
      }
    }
  }
}
int main() {
  sieve();
  int n, m;
  scanf("%d %d", &n, &m);
  m = m - (n - 1);
  int ptarget = *lower_bound(prime.begin(), prime.end(), (n - 1));
  int lastw = ptarget - (n - 2);
  for (int i = 1; i <= n - 1; i++) {
    if (i == n - 1) {
      ans.push_back(make_pair(i, make_pair(i + 1, lastw)));
    } else {
      ans.push_back(make_pair(i, make_pair(i + 1, 1)));
    }
  }
  for (int i = 1; i <= n && m > 0; i++) {
    for (int j = i + 2; j <= n && m > 0; j++) {
      ans.push_back(make_pair(i, make_pair(j, WMAX)));
      m--;
    }
  }
  printf("%d %d\n", ptarget, ptarget);
  for (int i = 0; i < ans.size(); i++) {
    int u = ans[i].first;
    int v = ans[i].second.first;
    int w = ans[i].second.second;
    printf("%d %d %d\n", u, v, w);
  }
  return 0;
}
