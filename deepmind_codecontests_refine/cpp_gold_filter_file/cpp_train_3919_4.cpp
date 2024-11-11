#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<int> vct[2][300010];
int gr[300010][2];
int main() {
  int n, cnt = 0;
  long long int ans = 0, tans = 0;
  char ch;
  int pg, prd = -1, pbl = -1, hb, hr;
  cin >> n;
  pg = -1;
  for (int i = 0, x; i < n; ++i) {
    cin >> x >> ch;
    if (ch == 'G') {
      if (pg == -1) {
        if (prd != -1) tans += x - prd;
        if (pbl != -1) tans += x - pbl;
      } else {
        if (prd != -1) tans += x - prd;
        if (pbl != -1) tans += x - pbl;
        tans = min(tans, x - pg + tans - max(hr, x - prd) - max(hb, x - pbl));
      }
      ans += tans;
      hr = hb = tans = 0;
      pg = prd = pbl = x;
    } else if (ch == 'R') {
      if (prd != -1) tans += x - prd, hr = max(hr, x - prd);
      prd = x;
    } else {
      if (pbl != -1) tans += x - pbl, hb = max(hb, x - pbl);
      pbl = x;
    }
  }
  ans += tans;
  cout << ans << endl;
}
