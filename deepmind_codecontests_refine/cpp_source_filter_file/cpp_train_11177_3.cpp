#include <bits/stdc++.h>
using namespace std;
int height[1002][1002];
int segpos[1002][1002];
vector<pair<long long, pair<int, int> > > yd;
vector<pair<pair<int, int>, pair<int, int> > > segment;
int fourp[4][2] = {0, 0, 1, 0, 0, 1, 1, 1};
int n;
long long vx, vy;
int tree[1002 * 1002 * 2], spare[1002 * 1002 * 2];
bool cmp(const pair<pair<int, int>, pair<int, int> > &a,
         const pair<pair<int, int>, pair<int, int> > &b) {
  long long x = a.first.first - b.first.first;
  long long y = a.first.second - b.first.second;
  return x * vx + y * vy < 0;
}
int find(int pos, int nodel, int noder, int fl, int fr) {
  if (fl <= nodel && fr >= noder) return max(tree[pos], spare[pos]);
  if (fr < nodel || fl > noder) return INT_MAX;
  int mid = (nodel + noder) / 2;
  int tmp = min(find(pos * 2, nodel, mid, fl, fr),
                find(pos * 2 + 1, mid + 1, noder, fl, fr));
  return max(tmp, spare[pos]);
}
int update(int pos, int nodel, int noder, int fl, int fr, int curval) {
  if (fr < nodel || fl > noder) return max(spare[pos], tree[pos]);
  if (fl <= nodel && fr >= noder) {
    if (curval > spare[pos]) spare[pos] = curval;
    return max(spare[pos], tree[pos]);
  }
  int mid = (nodel + noder) / 2;
  tree[pos] = min(update(pos * 2, nodel, mid, fl, fr, curval),
                  update(pos * 2 + 1, mid + 1, noder, fl, fr, curval));
  return max(spare[pos], tree[pos]);
}
vector<long long>::iterator twoSearch(vector<long long>::iterator first,
                                      vector<long long>::iterator last,
                                      long long val) {
  vector<long long>::iterator mid;
  --last;
  while (first <= last) {
    mid = first + (last - first) / 2;
    if (*mid == val)
      return mid;
    else if (*mid > val)
      last = mid - 1;
    else
      first = mid + 1;
  }
  return first;
}
int main() {
  cin >> n >> vx >> vy;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &height[i][j]);
  for (int x = 0; x <= n; x++)
    for (int y = 0; y <= n; y++)
      yd.push_back(make_pair(vx * y - vy * x, make_pair(x, y)));
  int difpos = 0, difnum = 0;
  sort(yd.begin(), yd.end());
  for (int i = 0; i < yd.size(); i++) {
    if (yd[i].first != yd[difpos].first) {
      difpos = i;
      difnum++;
    }
    segpos[yd[i].second.first][yd[i].second.second] = difnum;
  }
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++) {
      int Lpos, Rpos, dt;
      Lpos = INT_MAX;
      Rpos = INT_MIN;
      for (int d = 0; d < 4; d++) {
        dt = segpos[x + fourp[d][0]][y + fourp[d][1]];
        if (dt < Lpos) Lpos = dt;
        if (dt > Rpos) Rpos = dt;
      }
      segment.push_back(make_pair(make_pair(x, y), make_pair(Lpos, Rpos)));
    }
  sort(segment.begin(), segment.end(), cmp);
  long long ans = 0;
  for (int i = 0; i < segment.size(); i++) {
    int Lpos = segment[i].second.first;
    int Rpos = segment[i].second.second;
    int min = find(1, 0, difnum, Lpos, Rpos - 1);
    int curh = height[segment[i].first.first][segment[i].first.second];
    if (curh > min) ans += curh - min;
    update(1, 0, difnum, Lpos, Rpos - 1, curh);
  }
  cout << ans << endl;
  return 0;
}
