#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long b1, q, l, m, bad;
  set<long long> badNumber, sequence, analized;
  cin >> b1 >> q >> l >> m;
  while (m--) {
    cin >> bad;
    badNumber.insert(bad);
  }
  long long current = 1LL * b1;
  int terms = 0, sequenceBadNumbers = 0;
  while (abs(current) <= l && sequenceBadNumbers < 2) {
    if (badNumber.count(current)) {
      if (current == current * q) break;
      sequenceBadNumbers++;
      current = current * q;
    } else {
      sequenceBadNumbers = 0;
      if (sequence.count(current)) {
        terms = -1;
        break;
      }
      sequence.insert(current);
      terms++;
      current = current * q;
    }
  }
  if (terms == -1)
    cout << "inf" << endl;
  else
    cout << terms << endl;
}
int main() {
  solve();
  return 0;
}
