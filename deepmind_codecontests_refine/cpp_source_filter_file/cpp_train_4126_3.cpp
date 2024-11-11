#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long tn = n;
  long long ctr = 0;
  while (n > 0) {
    n /= 10;
    ctr++;
  }
  long long st = tn - (ctr - 1) * 9;
  set<long long> res;
  for (long long i = st; i <= tn; i++) {
    long long sm = i, ts = i;
    while (ts > 0) {
      sm = sm + (ts % 10);
      ts /= 10;
    }
    if (sm == tn) res.insert(i);
  }
  if (res.size()) {
    cout << res.size() << endl;
    for (set<long long>::iterator it = res.begin(); it != res.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
