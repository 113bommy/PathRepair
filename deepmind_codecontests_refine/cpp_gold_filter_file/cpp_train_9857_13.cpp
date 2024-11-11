#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k;
  long long c[100010], mc[100010];
  pair<int, int> p[100010];
  multiset<long long> maxk;
  long long maxs = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    p[i].second = i;
    cin >> p[i].first;
  }
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(p, p + n);
  mc[p[0].second] = c[p[0].second];
  for (int i = 1; i < n; i++) {
    maxk.insert(c[p[i - 1].second]);
    maxs += c[p[i - 1].second];
    if (maxk.size() > k) {
      maxs -= *maxk.begin();
      maxk.erase(maxk.begin());
    }
    mc[p[i].second] = maxs + c[p[i].second];
  }
  cout << mc[0];
  for (int i = 1; i < n; i++) cout << ' ' << mc[i];
  cout << endl;
}
