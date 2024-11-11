#include <bits/stdc++.h>
using namespace std;
long long cnt[9];
long long tot;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tot;
  for (int i = 1; i <= 8; i++) {
    cin >> cnt[i];
  }
  long long ctot = 0;
  long long mytot = 0;
  for (int i = 1; i <= 8; i++) {
    mytot += cnt[i] * i;
    long long use = max(0ll, cnt[i] - 100);
    use = min(max(0ll, (tot - 100 - ctot) / i), use);
    ctot += use * i;
    cnt[i] -= use;
    cnt[i] = min(100ll, cnt[i]);
  }
  long long goal = tot - ctot;
  cerr << tot << " " << ctot << endl;
  if (goal > 20000) {
    cout << mytot << endl;
    cerr << "bottlenecked" << endl;
  } else {
    bool possible[20000];
    memset(possible, 0, sizeof possible);
    possible[0] = true;
    for (int i = 1; i <= 8; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        for (int k = goal; k >= i; k--) {
          possible[k] = possible[k] || possible[k - i];
        }
      }
    }
    for (int i = goal; i >= 0; i--) {
      if (possible[i]) {
        cout << ctot + i << endl;
        exit(0);
      }
    }
  }
}
