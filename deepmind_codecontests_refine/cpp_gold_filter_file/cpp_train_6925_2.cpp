#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > Q;
pair<int, int> ar[200005];
set<int> vals;
map<int, int> freq;
long long getmin() { return *vals.begin(); }
void add(int x, int v) {
  if (freq[x] == 0) vals.insert(x);
  freq[x] += v;
  if (freq[x] == 0) vals.erase(x);
}
int main() {
  int d, n, m;
  scanf("%d%d%d", &d, &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &ar[i].first, &ar[i].second);
  }
  sort(ar, ar + n);
  ar[n].first = d;
  Q.push(make_pair(-m, 0));
  add(0, 1);
  long long ans = 0;
  int lst = 0;
  for (int i = 0; i <= n; ++i) {
    while (ar[i].first > -Q.top().first) {
      if (Q.top().second == getmin()) {
        ans += getmin() * ((-Q.top().first) - lst);
        lst = -Q.top().first;
      }
      add(Q.top().second, -1);
      Q.pop();
      if (Q.empty()) {
        puts("-1");
        return 0;
      }
    }
    ans += getmin() * (ar[i].first - lst);
    lst = ar[i].first;
    add(ar[i].second, 1);
    Q.push(make_pair(-(ar[i].first + m), ar[i].second));
  }
  cout << ans << endl;
}
