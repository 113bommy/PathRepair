#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000000")
using namespace std;
signed main() {
  long long n;
  cin >> n;
  set<long long> kek;
  long long st = 1;
  while (st <= 10000020) {
    kek.insert(st - 1);
    st *= 2;
  }
  vector<long long> ans;
  if (kek.count(n) == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (long long i = 0; i < 41; i++) {
    bitset<40> myb(n);
    bool flag = false;
    for (long long h = 39; h >= 0; --h) {
      if (myb[h] == 1) {
        for (long long j = h; j >= 0; --j) {
          if (myb[j] == 0) {
            long long hz = (1 << (j + 1)) - 1;
            ans.push_back(j + 1);
            n ^= hz;
            flag = true;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (kek.count(n) == 1) {
      cout << i + 1 << endl;
      for (long long h = 0; h < ans.size(); h++) cout << ans[h] << " ";
      cout << endl;
      return 0;
    }
    n++;
    i++;
    if (kek.count(n) == 1) {
      cout << i + 1 << endl;
      for (long long h = 0; h < ans.size(); h++) cout << ans[h] << " ";
      cout << endl;
      return 0;
    }
  }
}
