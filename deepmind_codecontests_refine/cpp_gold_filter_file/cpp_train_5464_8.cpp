#include <bits/stdc++.h>
using namespace std;
int n, a, b;
map<int, int> m, mapa;
long long bit[1001000];
void update(int idx, int v) {
  while (idx < 1001000) {
    bit[idx] += v;
    idx += (idx & -idx);
  }
}
long long query(int idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
int main(void) {
  ios ::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (m[a] == 0) {
      m[a] = a;
    }
    if (m[b] == 0) {
      m[b] = b;
    }
    swap(m[a], m[b]);
  }
  long long ans = 0;
  int curr = 1;
  if (m.begin()->first > 1) {
    mapa[1] = curr++;
  }
  for (auto it = m.begin(); it != m.end(); ++it) {
    mapa[it->first] = curr++;
    auto it2 = it;
    it2++;
    if (it2 != m.end() && it2->first > it->first + 1) {
      mapa[it->first + 1] = curr++;
    }
  }
  for (auto it = m.begin(); it != m.end(); ++it) {
    ans += (long long)query(1001000 - 1) - query(mapa[it->second]);
    update(mapa[it->second], 1);
    auto it2 = it;
    it2++;
    if (it2 != m.end() && it2->first > it->first + 1) {
      ans += (query(1001000 - 1) - query(mapa[it->first + 1])) *
             (long long)(it2->first - it->first - 1);
      update(mapa[it->first + 1], (it2->first - it->first - 1));
    }
  }
  cout << ans << "\n";
  return 0;
}
