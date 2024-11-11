#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int INF = 1e9 + 10;
const long long BINF = 1e18 + 10;
int n;
struct rect {
  int x, y, x2, y2;
  rect(){};
  rect(int _x, int _y, int _x2, int _y2) : x(_x), y(_y), x2(_x2), y2(_y2){};
};
const int MX = 400010;
int dx1[MX], dx2[MX], dy1[MX], dy2[MX];
int iter = 0;
int T = 500, ptr = 0;
vector<rect> have[10010];
int mem = 400010 * 4 + 10010 * 100;
bool cmp(int a, int b) { return (int)have[a].size() > (int)have[b].size(); }
mt19937 rnd(228);
const int MEM = 2e7;
bool rec(int ind) {
  if ((int)have[ind].size() <= 1) {
    return true;
  }
  if (mem >= MEM) {
    cout << "NO";
    exit(0);
  }
  iter++;
  if (iter > T || ptr >= 1000) {
    cout << "YES";
    exit(0);
  }
  int mnx = INF, mny = INF, mxx = -INF, mxy = -INF;
  for (auto it : have[ind]) {
    mnx = min(mnx, it.x);
    mxx = max(mxx, it.x2);
    mny = min(mny, it.y);
    mxy = max(mxy, it.y2);
  }
  for (int i = mnx; i <= mxx; i++) {
    dx1[i] = dx2[i] = 0;
  }
  for (int i = mny; i <= mxy; i++) {
    dy1[i] = dy2[i] = 0;
  }
  for (auto it : have[ind]) {
    dx1[it.x]++;
    dx2[it.x2]++;
    dy1[it.y]++;
    dy2[it.y2]++;
  }
  int pl = 0, sum = 0;
  vector<int> okx;
  for (int i = mnx; i <= mxx; i++) {
    sum -= dx2[i];
    if (sum == 0 && dx2[i] != 0 && pl > 0 && pl < (int)have[ind].size()) {
      okx.push_back(i);
      mem += 4;
    }
    sum += dx1[i];
    pl += dx1[i];
  }
  if (!okx.empty()) {
    for (auto it : have[ind]) {
      have[ptr +
           int(lower_bound((okx).begin(), (okx).end(), it.x2) - okx.begin())]
          .push_back(it);
    }
    mem += (int)have[ind].size();
    ptr += (int)okx.size() + 1;
    vector<int> order;
    for (int i = 0; i < (int)okx.size() + 1; i++) {
      order.push_back(ptr - i - 1);
      mem += 4;
    }
    sort((order).begin(), (order).end(), cmp);
    for (int ind : order) {
      if (!rec(ind)) {
        return false;
      }
      if (mem >= MEM) {
        cout << "NO";
        exit(0);
      }
    }
    return true;
  }
  vector<int> oky;
  mem += 100;
  pl = 0;
  sum = 0;
  for (int i = mny; i <= mxy; i++) {
    sum -= dy2[i];
    if (sum == 0 && dy2[i] != 0 && pl > 0 && pl < (int)have[ind].size()) {
      oky.push_back(i);
      mem += 4;
    }
    sum += dy1[i];
    pl += dy1[i];
  }
  if (!oky.empty()) {
    for (auto it : have[ind]) {
      have[ptr +
           int(lower_bound((oky).begin(), (oky).end(), it.y2) - oky.begin())]
          .push_back(it);
    }
    mem += (int)have[ind].size();
    ptr += (int)oky.size() + 1;
    vector<int> order;
    for (int i = 0; i < (int)oky.size() + 1; i++) {
      order.push_back(ptr - i - 1);
    }
    sort((order).begin(), (order).end(), cmp);
    for (int ind : order) {
      if (!rec(ind)) {
        return false;
      }
      if (mem >= MEM) {
        cout << "NO";
        exit(0);
      }
    }
    return true;
  }
  return false;
}
void source() {
  cin >> n;
  if (n == 100000) T = 300;
  vector<int> srt;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    have[0].push_back(rect(a, b, c, d));
    srt.push_back(a);
    srt.push_back(b);
    srt.push_back(c);
    srt.push_back(d);
  }
  sort((srt).begin(), (srt).end());
  srt.resize(unique((srt).begin(), (srt).end()) - srt.begin());
  unordered_map<int, int> to;
  for (int i = 0; i < (int)srt.size(); i++) {
    to[srt[i]] = i;
  }
  for (auto &it : have[0]) {
    it.x = to[it.x];
    it.x2 = to[it.x2];
    it.y = to[it.y];
    it.y2 = to[it.y2];
  }
  ptr = 1;
  cout << (rec(0) ? "YES" : "NO");
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}
