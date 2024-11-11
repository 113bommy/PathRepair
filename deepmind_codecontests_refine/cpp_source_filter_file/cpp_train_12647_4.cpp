#include <bits/stdc++.h>
using namespace std;
int n, q, a[500005], has[500005];
vector<int> vt[500005], even, odd;
long long int ans;
bool flag[500005];
void seieve() {
  for (int i = 2; i < 500005; i++) {
    if (flag[i]) continue;
    for (int j = i; j < 500005; j += i) flag[j] = true, vt[j].push_back(i);
  }
}
void collect(int num) {
  if (num == 1) return;
  even.clear();
  odd.clear();
  int siz = vt[num].size(), now, cnt;
  for (int i = 1; i < (1 << siz); i++) {
    now = 1, cnt = 0;
    for (int j = 0; j <= 10; j++) {
      if (i & (1 << j)) now *= vt[num][j], cnt++;
    }
    if (cnt & 1)
      odd.push_back(now);
    else
      even.push_back(now);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  seieve();
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(flag, false, sizeof(flag));
  long long int ans = 0, now = 0, tot, x, siz;
  while (q--) {
    scanf("%lld", &x);
    collect(a[x]);
    if (!flag[x]) {
      if (x == 1)
        ans += now;
      else {
        tot = 0;
        for (int i = 0; i < odd.size(); i++) {
          tot += has[odd[i]];
          has[odd[i]]++;
        }
        for (int i = 0; i < even.size(); i++) {
          tot -= has[even[i]];
          has[even[i]]++;
        }
        ans += (now - tot);
      }
      flag[x] = true;
      now++;
    } else {
      now--;
      if (x == 1)
        ans -= now;
      else {
        tot = 0;
        for (int i = 0; i < odd.size(); i++) {
          has[odd[i]]--;
          tot += has[odd[i]];
        }
        for (int i = 0; i < even.size(); i++) {
          has[even[i]]--;
          tot -= has[even[i]];
        }
        ans -= (now - tot);
      }
      flag[x] = false;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
