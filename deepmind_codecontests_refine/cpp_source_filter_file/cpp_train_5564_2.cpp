#include <bits/stdc++.h>
using namespace std;
string str[1100][11];
static int diff[1100][1100];
static int dist[11020];
int vis[1100] = {0};
int parent[1100];
vector<pair<long long int, long long int> > answer;
long long int sum = 0;
long long int n, m, w, k;
void add_to_tree(int curnode) {
  vis[curnode] = 1;
  sum += dist[curnode];
  answer.push_back(make_pair(curnode, parent[curnode]));
  for (int i = 1; i <= k; i++) {
    if (!vis[i]) {
      if (diff[i][curnode] < dist[i]) {
        dist[i] = diff[i][curnode];
        parent[i] = curnode;
      }
    }
  }
}
int find_closest() {
  int ans = 9999;
  dist[ans] = INT_MAX;
  for (int i = 1; i <= k; i++) {
    if ((!vis[i]) and (dist[i] < dist[ans])) {
      ans = i;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m >> k >> w;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> str[i][j];
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
          if (str[i][r][c] != str[j][r][c]) {
            diff[i][j] += w;
            diff[j][i] += w;
          }
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    diff[i][0] = diff[0][i] = dist[i] = n * m;
  }
  add_to_tree(0);
  for (int i = 1; i <= k; i++) {
    int z = find_closest();
    add_to_tree(z);
  }
  cout << sum << endl;
  for (int i = 1; i < answer.size(); i++) {
    cout << answer[i].first << " " << answer[i].second << endl;
  }
}
