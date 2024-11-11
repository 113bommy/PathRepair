#include <bits/stdc++.h>
using namespace std;
void f() {
  int n, I;
  cin >> n >> I;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    mp[num]++;
  }
  int k = (8 * I) / n;
  long long int K = (1LL << min(k, 20));
  if (K >= mp.size())
    cout << 0;
  else {
    map<int, int>::iterator l, r, it;
    l = mp.begin();
    long long int changes = 0, minchanges = n, count = 0;
    for (it = mp.begin(); it != mp.end(); it++, count++) {
      if (count >= K)
        changes += it->second;
      else if (count == K - 1)
        r = it;
    }
    r++;
    minchanges = min(minchanges, changes);
    while (r != mp.end()) {
      changes += l->second;
      changes -= r->second;
      minchanges = min(minchanges, changes);
      l++;
      r++;
    }
    cout << minchanges;
  }
}
int main() {
  f();
  return 0;
}
