#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  pair<long long, long long> vet[7009];
  map<long long, long long> freq;
  for (long long i = 0; i < n; i++) {
    cin >> vet[i].first;
    freq[vet[i].first]++;
  }
  for (long long i = 0; i < n; i++) {
    cin >> vet[i].second;
  }
  set<long long> f2;
  for (auto e : freq) {
    if (e.second >= 2) f2.insert(e.first);
  }
  long long ans = 0;
  if (f2.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (f2.find(vet[i].first) != f2.end()) {
      ans += vet[i].second;
    } else {
      bool let = true;
      for (auto e : f2) {
        if ((vet[i].first | e) != e) let = false;
      }
      if (let) ans += vet[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}
