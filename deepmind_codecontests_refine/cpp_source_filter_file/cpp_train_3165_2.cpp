#include <bits/stdc++.h>
using namespace std;
bool visited[105];
vector<long long> ar[1000];
vector<long long> y;
void dfs(long long node) {
  y.push_back(node);
  visited[node] = 1;
  for (int i = 0; i < ar[node].size(); i++) {
    long long child = ar[node][i];
    if (!visited[child]) {
      dfs(child);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b, c;
  vector<pair<long long, long long> > v;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    if (a == 1) {
      for (int i = 0; i < v.size(); i++) {
        long long j = v.size() - 1;
        if ((c > v[i].first && c < v[i].second) ||
            (b > v[i].first && b < v[i].second)) {
          ar[j].push_back(i);
        }
        if ((v[i].first > b && v[i].first < c) ||
            (v[i].second > b && v[i].second < c)) {
          ar[i].push_back(j);
        }
      }
      v.push_back(make_pair(b, c));
    } else {
      b--;
      c--;
      y.clear();
      for (int i = 0; i < 102; i++) {
        visited[i] = 0;
      }
      dfs(b);
      bool yes = 0;
      for (int i = 0; i < y.size(); i++) {
        if (y[i] == c) {
          yes = 1;
        }
      }
      if (yes) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}
