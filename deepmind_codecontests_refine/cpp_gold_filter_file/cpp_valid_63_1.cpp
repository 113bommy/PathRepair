#include <bits/stdc++.h>
using namespace std;
long long int findParent(long long int node, vector<long long int> &parent) {
  if (parent[node] == node) return node;
  parent[node] = findParent(parent[node], parent);
  return parent[node];
}
void solve(long long int caseno) {
  long long int n, m1, m2, v1, v2, p1, p2;
  cin >> n >> m1 >> m2;
  vector<long long int> par1(n + 1, 0), par2(n + 1, 0), rank1(n + 1, 0),
      rank2(n + 1, 0);
  vector<pair<long long int, long long int> > ans;
  for (long long int i = 1; i <= n; i++) {
    par1[i] = par2[i] = i;
  }
  for (long long int i = 0; i < m1; i++) {
    cin >> v1 >> v2;
    p1 = findParent(v1, par1);
    p2 = findParent(v2, par1);
    if (rank1[p1] < rank1[p2]) {
      par1[p1] = p2;
    } else if (rank1[p1] > rank1[p2]) {
      par1[p2] = p1;
    } else {
      par1[p2] = p1;
      rank1[p1]++;
    }
  }
  for (long long int i = 0; i < m2; i++) {
    cin >> v1 >> v2;
    p1 = findParent(v1, par2);
    p2 = findParent(v2, par2);
    if (rank2[p1] < rank2[p2]) {
      par2[p1] = p2;
    } else if (rank2[p1] > rank2[p2]) {
      par2[p2] = p1;
    } else {
      par2[p2] = p1;
      rank2[p1]++;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = i + 1; j <= n; j++) {
      if (findParent(i, par1) != findParent(j, par1) &&
          findParent(i, par2) != findParent(j, par2)) {
        ans.push_back({i, j});
        p1 = findParent(i, par1);
        p2 = findParent(j, par1);
        if (rank1[p1] < rank1[p2]) {
          par1[p1] = p2;
        } else if (rank1[p1] > rank1[p2]) {
          par1[p2] = p1;
        } else {
          par1[p2] = p1;
          rank1[p1]++;
        }
        p1 = findParent(i, par2);
        p2 = findParent(j, par2);
        if (p1 == p2) continue;
        if (rank2[p1] < rank2[p2]) {
          par2[p1] = p2;
        } else if (rank2[p1] > rank2[p2]) {
          par2[p2] = p1;
        } else {
          par2[p2] = p1;
          rank2[p1]++;
        }
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
