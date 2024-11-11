#include <bits/stdc++.h>
using namespace std;
const long long N = 1010;
long long n, ted, width, height, lim, ans = 1 << 28;
pair<pair<long long, long long>, pair<long long, bool> > inp[N];
set<pair<long long, long long> > chng;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> inp[i].first.second >> inp[i].first.first;
    if (inp[i].first.first < inp[i].first.second) {
      inp[i].second.second = 1;
      chng.insert(pair<long long, long long>(
          inp[i].first.second - inp[i].first.first, i));
      ++ted;
      swap(inp[i].first.first, inp[i].first.second);
    }
    inp[i].second.first = i;
    width += inp[i].first.second;
    lim = max(lim, inp[i].first.second);
  }
  sort(inp + 1, inp + n + 1);
  height = inp[n].first.first;
  for (long long i = n; i >= 0; --i) {
    height = max(inp[i].first.first, lim);
    long long sres = width, cnt = 0;
    for (set<pair<long long, long long> >::iterator it = chng.begin();
         cnt < ted - (n / 2) and it != chng.end(); ++it) {
      sres += (*it).first;
      ++cnt;
    }
    if (ted - cnt > (n / 2)) break;
    sres *= height;
    ans = min(ans, sres);
    if (inp[i].second.second) {
      ted--;
      chng.erase(pair<long long, long long>(
          inp[i].first.first - inp[i].first.second, inp[i].second.first));
    } else
      ted++;
    width += inp[i].first.first - inp[i].first.second;
    if (inp[i].first.first < lim) break;
  }
  cout << ans << endl;
  return 0;
}
