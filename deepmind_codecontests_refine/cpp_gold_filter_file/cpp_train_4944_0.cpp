#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000"]
#pragma GCC optimize("Ofast"]
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native"]
using namespace std;
signed main() {
  long long int n;
  cin >> n;
  deque<long long int> a, b;
  long long int k1;
  cin >> k1;
  for (long long int i = 0; i < k1; i++) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  long long int k2;
  cin >> k2;
  for (long long int i = 0; i < k2; i++) {
    long long int x;
    cin >> x;
    b.push_back(x);
  }
  long long int cnt = 0;
  while (true) {
    if (cnt > 1000) {
      cout << -1 << "\n";
      return 0;
    } else {
      cnt++;
      long long int cardf = a.front();
      a.pop_front();
      long long int cards = b.front();
      b.pop_front();
      if (cardf > cards) {
        a.push_back(cards);
        a.push_back(cardf);
      } else {
        b.push_back(cardf);
        b.push_back(cards);
      }
      if (a.size() == 0) {
        cout << cnt << " " << 2 << "\n";
        return 0;
      } else if (b.size() == 0) {
        cout << cnt << " " << 1 << "\n";
        return 0;
      }
    }
  }
  return 0;
}
