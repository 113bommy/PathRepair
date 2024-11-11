#include <bits/stdc++.h>
using namespace std;
ifstream fi("test.txt");
ifstream fir("inp.txt");
ofstream fo("out.txt");
const long long MOD = 1e9 + 7;
const long long base = 269;
const int ooi = 1 << 30;
const int N = 1e5 + 5;
long long n, m, q, k, pos, rs, t, T, cnt;
long long maxx = -1e9, minn = 1e9;
long long a[105][105];
vector<pair<long long, long long>> v;
int main() {
  cin >> n >> m;
  for (long long(i) = 0; (i) < (n); (i)++) {
    string s;
    cin >> s;
    for (long long(j) = 0; (j) < (s.length()); (j)++) {
      if (s[j] == '*') v.push_back(make_pair(i + 1, j + 1));
    }
  }
  for (long long(i) = 1; (i) <= (105); (i)++)
    for (long long(j) = 1; (j) <= (105); (j)++) {
      int dis1, dis2;
      dis1 = (i - v[0].first) * (i - v[0].first) +
             (j - v[0].second) * (j - v[0].second);
      dis2 = (v[1].first - v[2].first) * (v[1].first - v[2].first) +
             (v[1].second - v[2].second) * (v[1].second - v[2].second);
      int dis3, dis4;
      dis3 = (i - v[1].first) * (i - v[1].first) +
             (j - v[1].second) * (j - v[1].second);
      dis4 = (v[0].first - v[2].first) * (v[0].first - v[2].first) +
             (v[0].second - v[2].second) * (v[0].second - v[2].second);
      int dis5, dis6;
      dis5 = (i - v[2].first) * (i - v[2].first) +
             (j - v[2].second) * (j - v[2].second);
      dis6 = (v[0].first - v[1].first) * (v[0].first - v[1].first) +
             (v[0].second - v[1].second) * (v[0].second - v[1].second);
      if (dis1 == dis2 && dis3 == dis4 && i <= n && j <= m && dis5 == dis6)
        return cout << i << " " << j, 0;
    }
}
