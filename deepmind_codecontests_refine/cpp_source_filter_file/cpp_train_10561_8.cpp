#include <bits/stdc++.h>
using namespace std;
int s[3][2000];
multiset<int> f[3];
int main(int argc, const char* argv[]) {
  int k, n[3], t[3];
  cin >> k;
  for (int i = 0; i < 3; i++) {
    cin >> n[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n[i]; j++) {
      f[i].insert(0);
    }
  }
  long long mx = 0;
  while (k) {
    int t1 = *f[0].begin();
    int t2 = *f[1].begin();
    int t3 = *f[2].begin();
    t2 = max(t2, t1 + t[0]);
    t3 = max(t3, t2 + t[1]) + t[2];
    f[0].erase(f[0].begin());
    f[0].insert(t3 - t[0] - t[1]);
    f[1].erase(f[1].begin());
    f[1].insert(t3 - t[1]);
    f[2].erase(f[2].begin());
    f[2].insert(t3);
    if (t3 > mx) mx = t3;
    k--;
  }
  cout << mx;
  return 0;
}
