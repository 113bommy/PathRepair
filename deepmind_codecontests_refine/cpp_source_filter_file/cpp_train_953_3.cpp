#include <bits/stdc++.h>
using namespace std;
long long arr[400007];
int main() {
  long long n, b, x;
  cin >> n >> b;
  map<long long, long long> mp;
  map<long long, long long>::iterator it;
  map<long long, long long>::reverse_iterator rit;
  for (long long i = 1; i <= n; ++i) {
    cin >> x;
    mp[x]++;
  }
  long long lg = ceil(log2(mp.size()));
  long long need = lg * n, have = b * 8;
  if (need <= have)
    cout << 0 << endl;
  else {
    long long mn = have / n;
    long long so = pow(2, mn);
    long long rmv = mp.size() - so, s1 = 0, s2 = 0, i, ans = 1e9;
    vector<long long> v;
    for (it = mp.begin(); it != mp.end(); ++it) {
      v.push_back(it->second);
      s2 += it->second;
    }
    for (long long i = 0; i < v.size(); ++i) {
      if (i < so)
        s1 += v[i];
      else {
        ans = min(ans, s2 - s1);
        s1 += v[i];
        s1 -= v[i - so];
      }
    }
    cout << min(ans, s1) << endl;
  }
}
