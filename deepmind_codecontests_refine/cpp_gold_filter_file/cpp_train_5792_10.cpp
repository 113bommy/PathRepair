#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
vector<int> open[maxN];
vector<pair<int, int> > box;
int a[maxN], b[maxN], p[maxN];
priority_queue<int> demolished;
bool cmp(int a, int b) { return p[a] < p[b]; }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    box.push_back(make_pair(b[i], i));
  }
  sort(box.begin(), box.end());
  for (int i = 1; i <= m; i++) cin >> p[i];
  int ind = 0;
  for (int i = n; i >= 1; i--) {
    while (ind < box.size() && box[ind].first <= a[i]) {
      open[i].push_back(box[ind].second);
      ind++;
    }
  }
  for (int i = 1; i <= max(m, n); i++)
    sort(open[i].begin(), open[i].end(), cmp);
  long long gain = 0;
  for (int i = 1; i <= n; i++) {
    gain += a[i];
    for (int j = 0; j < open[i].size(); j++) {
      int cur = open[i][j];
      if (p[cur] > gain) {
        if (!demolished.empty() && demolished.top() > p[cur]) {
          gain += demolished.top();
          demolished.pop();
          demolished.push(p[cur]);
          gain -= p[cur];
        } else
          break;
      } else {
        demolished.push(p[cur]);
        gain -= p[cur];
      }
    }
  }
  cout << demolished.size() << endl;
}
