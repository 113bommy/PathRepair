#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> req[1000];
pair<int, int> t[1000];
int n, k;
bool cmp1(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first != b.first.first)
    return a.first.first > b.first.first;
  else if (a.first.second != b.first.second)
    return a.first.second < b.first.second;
  else
    return a.second < b.second;
}
bool cmp2(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second < b.second;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    req[i].second = i;
    cin >> req[i].first.second >> req[i].first.first;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    t[i].second = i;
    cin >> t[i].first;
  }
  sort(req, req + n, cmp1);
  sort(t, t + k, cmp2);
  int c = 0;
  int used[1001] = {0};
  int m = 0;
  int h[1001] = {0};
  for (int i = 0; i < n; i++) {
    int mint = 10001;
    int mind = -1;
    int p = req[i].first.second;
    for (int j = 0; j < k; j++) {
      if (p <= t[j].first && !used[j]) {
        mind = j;
        break;
      }
    }
    if (mind == -1)
      continue;
    else {
      used[mind] = 1;
      m++;
      c += req[i].first.first;
      h[req[i].second] = t[mind].second + 1;
    }
  }
  cout << m << " " << c << endl;
  for (int i = 0; i < n; i++) {
    if (!h[i]) continue;
    cout << i + 1 << " " << h[i] << endl;
  }
  return 0;
}
