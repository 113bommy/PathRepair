#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100, inf = 0x3f3f3f3f;
int n;
int a[maxn];
int l[maxn], r[maxn];
map<int, int> mp;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  stack<pair<int, int> > s;
  s.push(pair<int, int>(inf, 0));
  for (int i = 1; i <= n; ++i) {
    while (s.top().first <= a[i]) s.pop();
    l[i] = s.top().second;
    s.push(pair<int, int>(a[i], i));
  }
  while (!s.empty()) s.pop();
  s.push(pair<int, int>(inf, n + 1));
  for (int i = n; i >= 1; --i) {
    while (s.top().first <= a[i]) s.pop();
    r[i] = s.top().second;
    s.push(pair<int, int>(a[i], i));
  }
  sort(a + 1, a + 1 + n, greater<int>());
  map<int, int> ms;
  ms[n] = 1;
  int k = a[1] + 1, cnt = 1;
  for (int i = 1; i <= n; ++i) {
    int p = mp[a[i]];
    int len = r[p] - l[p] - 1;
    int len1 = p - l[p] - 1;
    int len2 = r[p] - p - 1;
    ms[len]--;
    if (ms[len] == 0) ms.erase(len);
    if (len1) ms[len1]++;
    if (len2) ms[len2]++;
    if (ms.size() == 1 && (int)ms.begin()->second >= cnt) {
      k = a[i + 1] + 1;
      cnt = (int)ms.begin()->second;
    }
  }
  cout << k << endl;
  return 0;
}
