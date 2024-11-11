#include <bits/stdc++.h>
using namespace std;
const long MAX_N = 30, INF = 1e9;
long n;
long arr[MAX_N][5];
vector<pair<pair<long, long>, long> > vec1, vec2;
string ans;
map<pair<pair<long, long>, long>, string> mm1, mm2;
void build1(long mx, long cnt, long a, long b, long c, string id = "") {
  if (cnt == mx) {
    vec1.push_back(make_pair(make_pair(a - b, b - c), a));
    mm1[make_pair(make_pair(a - b, b - c), a)] = id;
    return;
  }
  build1(mx, cnt + 1, a + arr[cnt][0], b + arr[cnt][1], c, id + '2');
  build1(mx, cnt + 1, a + arr[cnt][0], b, c + arr[cnt][2], id + '1');
  build1(mx, cnt + 1, a, b + arr[cnt][1], c + arr[cnt][2], id + '0');
}
void build2(long mx, long cnt, long a, long b, long c, string id = "") {
  if (cnt == mx) {
    vec2.push_back(make_pair(make_pair(a - b, b - c), a));
    mm2[make_pair(make_pair(a - b, b - c), a)] = id;
    return;
  }
  build2(mx, cnt + 1, a + arr[cnt][0], b + arr[cnt][1], c, id + '2');
  build2(mx, cnt + 1, a + arr[cnt][0], b, c + arr[cnt][2], id + '1');
  build2(mx, cnt + 1, a, b + arr[cnt][1], c + arr[cnt][2], id + '0');
}
int32_t main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  long tm = floor(float(n) / 2);
  build1(tm, 0, 0, 0, 0);
  build2(n, tm, 0, 0, 0);
  sort(vec2.begin(), vec2.end());
  long k, mx = -INF;
  pair<pair<pair<long, long>, long>, pair<pair<long, long>, long> > pans;
  for (pair<pair<long, long>, long> x : vec1) {
    k = upper_bound(
            vec2.begin(), vec2.end(),
            make_pair(make_pair(-x.first.first, -x.first.second + 1), -INF)) -
        vec2.begin();
    k--;
    if (k >= 0 and vec2[k].first.first == -x.first.first and
        vec2[k].first.second == -x.first.second) {
      if (x.second + vec2[k].second > mx) {
        mx = x.second + vec2[k].second;
        pans = make_pair(x, vec2[k]);
      }
    }
  }
  ans = mm1[pans.first] + mm2[pans.second];
  if (mx == -INF) {
    cout << "Impossible"
         << "\n";
    return 0;
  }
  for (char c : ans) {
    if (c == '0')
      cout << "MW"
           << "\n";
    if (c == '1')
      cout << "LW"
           << "\n";
    if (c == '2')
      cout << "LM"
           << "\n";
  }
}
