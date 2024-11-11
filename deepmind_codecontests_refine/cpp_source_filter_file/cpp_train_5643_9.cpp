#include <bits/stdc++.h>
using namespace std;
int n, a, b, r[200005], k;
vector<int> v, has, sta[200005], en[200005];
set<pair<int, int> > s;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    r[i] = b;
    sta[a].push_back(i);
    en[b].push_back(i);
  }
  for (int i = 1; i <= 200005; i++) {
    for (int x : sta[i]) s.insert({r[x], x});
    while (s.size() > k) {
      auto it = s.end();
      it--;
      has.push_back(it->second);
      s.erase(it);
    }
    for (int x : en[i]) s.erase({r[x], x});
  }
  cout << has.size() << endl;
  for (int i = 0; i < has.size(); i++) cout << has[i] << " ";
  cout << endl;
}
