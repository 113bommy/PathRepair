#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v;
map<long long, long long> mapp;
long long check(long long cnt, long long sz) {
  if (cnt % sz == 0)
    return cnt / sz;
  else {
    if (cnt % sz == sz - 1)
      return cnt / sz + 1;
    else if (cnt / sz >= (sz - cnt % sz))
      return cnt / sz + 1;
    else
      return -1;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    v.clear();
    mapp.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      long long num;
      cin >> num;
      mapp[num]++;
    }
    for (pair<long long, long long> p : mapp) v.push_back(p.second);
    sort(v.begin(), v.end());
    long long ans = LLONG_MAX;
    for (int cs = 1; cs <= v[0] + 1; ++cs) {
      long long cans = 0;
      for (int i = 0; i < v.size(); ++i) {
        long long c = check(v[i], cs);
        if (c == -1) {
          cans = LLONG_MAX;
          break;
        }
        cans += c;
      }
      ans = min(ans, cans);
    }
    cout << ans << '\n';
  }
  return 0;
}
