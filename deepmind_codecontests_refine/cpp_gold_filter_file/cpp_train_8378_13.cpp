#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> v[5];
long long p[60], h, q, frst, lst, rght, lft, c, ans, res;
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  p[0] = 1;
  for (int i = 1; i <= 55; i++) p[i] = p[i - 1] * 2;
  cin >> h >> q;
  for (int k = 1, i; k <= q; k++) {
    cin >> i >> lft >> rght >> ans;
    v[ans].push_back(make_pair(lft * p[h - i], (rght + 1) * p[h - i] - 1));
  }
  frst = p[h - 1];
  lst = p[h] - 1;
  for (int i = 0; i < v[1].size(); i++) {
    if (v[1][i].first > frst) frst = v[1][i].first;
    if (v[1][i].second < lst) lst = v[1][i].second;
  }
  if (lst < frst) {
    cout << "Game cheated!\n";
    return 0;
  }
  sort(v[0].begin(), v[0].end());
  lft = rght = -1;
  for (int i = 0; i < v[0].size(); i++) {
    if (v[0][i].first > rght) {
      if (rght != -1) v[2].push_back(make_pair(lft, rght));
      lft = v[0][i].first;
    }
    rght = max(rght, v[0][i].second);
  }
  if (rght != -1) v[2].push_back(make_pair(lft, rght));
  c = lst - frst + 1;
  for (int i = 0; i < v[2].size(); i++) {
    rght = min(v[2][i].second, lst);
    if (frst > rght) continue;
    lft = max(v[2][i].first, frst);
    if (lst < lft) break;
    c -= rght - lft + 1;
    if (lft > frst + 1) break;
    if (lft == frst + 1) res = frst;
    frst = rght + 1;
    if (frst > lst) break;
  }
  if (frst == lst) res = frst;
  if (c == 1)
    cout << res << "\n";
  else if (c == 0)
    cout << "Game cheated!\n";
  else
    cout << "Data not sufficient!\n";
  return 0;
}
