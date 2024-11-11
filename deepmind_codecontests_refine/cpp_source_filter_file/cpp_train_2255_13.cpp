#include <bits/stdc++.h>
#pragma _attribute_((optimize("-O2")))
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n >> q;
  vector<long long> in, aq;
  set<pair<long long, long long> > all;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    sum += tmp;
    all.insert({sum, i});
    in.push_back(tmp);
  }
  for (long long i = 0; i < q; i++) {
    long long tmp;
    cin >> tmp;
    aq.push_back(tmp);
  }
  long long now = 0;
  for (long long i = 0; i < q; i++) {
    now += aq[i];
    auto it = all.lower_bound({now, 0});
    if (it == all.end())
      cout << n << endl;
    else {
      long long tmp = 0;
      if (it->first == now)
        tmp = n - it->second - 1;
      else
        tmp = n - it->second;
      if (tmp == 0) tmp = n;
      cout << tmp << endl;
    }
    if (now > sum) now = 0;
  }
  return 0;
}
