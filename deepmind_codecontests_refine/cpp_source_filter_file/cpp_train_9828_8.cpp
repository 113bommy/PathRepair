#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
multiset<int> S, now;
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
    ans += x;
  }
  map<int, int>::iterator it;
  for (it = mp.end(); it != mp.begin();) {
    int x = (--it)->first, cnt = it->second;
    for (; cnt && !S.empty() && !*S.begin();)
      --cnt, S.erase(S.begin()), now.insert(x);
    for (; cnt > 1 && !S.empty();) {
      int y = *S.begin();
      if (y >= 2 * x) break;
      S.erase(S.begin());
      cnt -= 2;
      if (y < x)
        now.insert(x), now.insert(x);
      else
        now.insert(2 * x - y), now.insert(y);
    }
    if (cnt && !S.empty() && *S.begin() < x)
      S.erase(*S.begin()), now.insert(x), now.insert(0), cnt--;
    for (; cnt; cnt--) now.insert(0);
    for (; !now.empty(); S.insert(*now.begin()), now.erase(now.begin()))
      ;
  }
  for (auto i : S) ans -= i;
  cout << ans << endl;
}
