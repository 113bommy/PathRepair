#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, int> mp, ins;
pair<long long, int> a[7007];
long long b[7007];
vector<pair<long long, int> > v;
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i].first);
    a[i].second = i;
    mp[a[i].first]++;
  }
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  for (int i = 0; i < v.size(); i++) sum += b[v[i].second];
  for (int i = 0; i < n; i++)
    if (mp[a[i].first] >= 2) {
      sum += b[i];
      if (!ins[a[i].first])
        ins[a[i].first] = 1, v.push_back(pair<long long, int>(a[i].first, i));
    }
  sort(a, a + n, greater<pair<long long, int> >());
  for (int i = 0; i < n; i++) {
    if (mp[a[i].first] >= 2) continue;
    bool first = 0;
    int cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k <= log2(a[i].first); k++)
        if (!(v[j].first & (1 << k)) and a[i].first & (1 << k)) {
          cnt++;
          break;
        }
    }
    if (cnt < v.size()) sum += b[a[i].second];
  }
  cout << sum << endl;
}
