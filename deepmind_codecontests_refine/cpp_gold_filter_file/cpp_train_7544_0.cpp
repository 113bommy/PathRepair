#include <bits/stdc++.h>
using namespace std;
long long modulo(long long x, long long y) { return ((x % y) + y) % y; }
void solve() {
  int w, h, n;
  cin >> w >> h >> n;
  int len[] = {w, h};
  set<int> cuts[2];
  map<int, int> chunks[2];
  for (int(i) = 0; (i) < (2); (i)++) cuts[i].insert(0);
  for (int(i) = 0; (i) < (2); (i)++) cuts[i].insert(len[i]);
  for (int(i) = 0; (i) < (2); (i)++) chunks[i][len[i]] = 1;
  for (int(___i) = 0; (___i) < (n); (___i)++) {
    char c;
    int x;
    cin >> c >> x;
    int idx = (c == 'V') ? 0 : 1;
    int after, before;
    {
      auto it = cuts[idx].upper_bound(x);
      after = *it;
      --it;
      before = *it;
    }
    cuts[idx].insert(x);
    {
      auto it = chunks[idx].find(after - before);
      it->second--;
      if (it->second == 0) {
        chunks[idx].erase(it);
      }
    }
    chunks[idx][after - x]++;
    chunks[idx][x - before]++;
    long long area = 1;
    for (int(i) = 0; (i) < (2); (i)++) {
      auto it = chunks[i].end();
      --it;
      area *= it->first;
    }
    cout << area << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
