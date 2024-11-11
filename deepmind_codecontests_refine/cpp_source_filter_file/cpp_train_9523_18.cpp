#include <bits/stdc++.h>
using namespace std;
bool alldone(vector<bool> done) {
  for (int i = 0; i < done.size(); ++i) {
    if (!done[i]) return false;
  }
  return true;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<bool> done(n, false);
  vector<int> ans(n);
  long long tofind = m;
  int digval, base;
  long long totans;
  int rem;
  int st = 0;
  int end = n - 1;
  while (!alldone(done)) {
    for (int i = 0; i < n; ++i) {
      if (!done[i]) {
        base = digval = i + 1;
        rem = n - i - 1;
        break;
      }
    }
    totans = 1 << rem;
    while (totans < 2 * tofind && totans > 1) {
      digval++;
      totans >>= 1;
      tofind -= totans;
    }
    ans[st++] = digval;
    done[digval - 1] = true;
    for (; base < digval; ++base) {
      done[base - 1] = true;
      ans[end--] = base;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
