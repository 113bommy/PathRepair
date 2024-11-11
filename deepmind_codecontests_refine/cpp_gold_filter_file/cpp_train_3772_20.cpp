#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
pair<int, int> dibawah[2 * MAXN], diatas[2 * MAXN], row[MAXN], col[MAXN];
vector<pair<int, int> > v;
int t[10];
void init() {
  for (int i = 0; i < MAXN; i++) {
    dibawah[i].first = diatas[i].first = row[i].first = col[i].first = MAXN + 1;
    dibawah[i].second = diatas[i].second = row[i].second = col[i].second = -1;
  }
  for (int i = MAXN; i <= 2 * MAXN - 1; i++) {
    dibawah[i].first = diatas[i].first = MAXN + 1;
    dibawah[i].second = diatas[i].second = -1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
    dibawah[b - a + n].first = min(dibawah[b - a + n].first, a);
    dibawah[b - a + n].second = max(dibawah[b - a + n].second, a);
    diatas[a + b].first = min(diatas[a + b].first, a);
    diatas[a + b].second = max(diatas[a + b].second, a);
    row[a].first = min(row[a].first, b);
    row[a].second = max(row[a].second, b);
    col[b].first = min(col[b].first, a);
    col[b].second = max(col[b].second, a);
  }
  for (int i = 0; i < v.size(); i++) {
    int a = v[i].first, b = v[i].second;
    int res = 0;
    if (dibawah[b - a + n].first < a) res++;
    if (dibawah[b - a + n].second > a) res++;
    if (diatas[a + b].first < a) res++;
    if (diatas[a + b].second > a) res++;
    if (row[a].first < b) res++;
    if (row[a].second > b) res++;
    if (col[b].first < a) res++;
    if (col[b].second > a) res++;
    t[res]++;
  }
  for (int i = 0; i < 9; i++) {
    cout << t[i] << (i == 8 ? '\n' : ' ');
  }
}
