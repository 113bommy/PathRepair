#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> v[i];
  }
  map<int, int> conj;
  for (int i = 0; i < (int)(n); i++) {
    int x;
    cin >> x;
    conj[x]++;
  }
  for (int i = 0; i < (int)(n); i++) {
    auto pos = conj.lower_bound(n - v[i]);
    auto pos2 = conj.begin();
    if (pos == conj.end() ||
        ((v[i] + pos2->first) % n) <= ((v[i] + pos->first) % n)) {
      cout << (v[i] + pos2->first) % n << " ";
      pos2->second--;
      if (pos2->second == 0) {
        conj.erase(pos2->first);
        continue;
      }
    } else {
      cout << (v[i] + pos->first) % n << " ";
      pos->second--;
      if (pos->second == 0) {
        conj.erase(pos->first);
        continue;
      }
    }
  }
  return 0;
}
