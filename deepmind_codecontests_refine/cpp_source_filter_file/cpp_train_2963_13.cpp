#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 0.000000001;
const double PI = 3.141592653589793;
const long long LLINF = 99999999999999999LL;
const int MAX_N = 100005;
const int MOD = 1000000007;
struct Edge {
  int x, y, c;
};
int N, M, K;
pair<int, int> val[MAX_N * 3];
vector<int> v[MAX_N * 3];
string s, x, y;
vector<string> essay;
map<string, int> Nr;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
               greater<pair<pair<int, int>, int> > >
    H;
bool vis[MAX_N * 3];
int countRs(string s) {
  int ret = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == 'r') ++ret;
  return ret;
}
void lower(string &s) {
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
}
int main() {
  for (int i = 1; i < 3 * MAX_N; ++i) val[i] = make_pair(INF, INF);
  cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> s;
    lower(s);
    essay.push_back(s);
    if (!Nr[s]) Nr[s] = ++cnt;
    int temp = countRs(s);
    H.push(make_pair(make_pair(temp, s.size()), Nr[s]));
    val[Nr[s]] = make_pair(temp, s.size());
  }
  cin >> M;
  for (int i = 1; i <= M; ++i) {
    cin >> x >> y;
    lower(x);
    lower(y);
    if (!Nr[x]) Nr[x] = ++cnt;
    if (!Nr[y]) Nr[y] = ++cnt;
    int indX = Nr[x], indY = Nr[y];
    v[indY].push_back(indX);
    int temp = countRs(y);
    H.push(make_pair(make_pair(temp, y.size()), indY));
    val[Nr[y]] = make_pair(temp, y.size());
  }
  while (!H.empty()) {
    int x = H.top().second;
    H.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = 0; i < (int)v[x].size(); ++i) {
      int y = v[x][i];
      if (val[x] < val[y]) {
        val[y] = val[x];
        H.push(make_pair(val[y], y));
      }
    }
  }
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < N; ++i) {
    ans1 += val[Nr[essay[i]]].first;
    ans2 += val[Nr[essay[i]]].second;
  }
  cout << ans1 << " " << ans2;
  return 0;
}
