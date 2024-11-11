#include <bits/stdc++.h>
using namespace std;
typedef struct numb {
  int n, b, e;
} Numb;
bool cond(Numb A, Numb B) { return (A.n < B.n); }
vector<int> vec[int(1e5) + 10];
int vis[int(1e5) + 10];
map<int, vector<int> > resp;
Numb v[int(1e5) + 10];
void DFS(int idx, int val) {
  vis[idx] = val;
  for (int i = 0, __ = int(vec[idx].size()); i < __; i++) {
    if (!vis[vec[idx][i]]) DFS(vec[idx][i], val);
  }
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int val[n];
  for (int i = 1, __ = n + 1; i < __; i++) cin >> v[i].n, v[i].b = i;
  sort(v + 1, v + n + 1, cond);
  for (int i = 1, __ = n + 1; i < __; i++) {
    v[i].e = i;
    vec[v[i].b].push_back(v[i].e);
    vec[v[i].e].push_back(v[i].b);
  }
  for (int i = 1, __ = n + 1; i < __; i++) {
    if (!vis[i]) DFS(i, i);
    resp[vis[i]].push_back(i);
  }
  cout << resp.size() << endl;
  for (map<int, vector<int> >::iterator it = resp.begin(); it != resp.end();
       it++) {
    cout << it->second.size() << " ";
    for (int j = 0, __ = int(it->second.size()); j < __; j++) {
      if (j + 1 != it->second.size())
        cout << it->second[j] << " ";
      else
        cout << it->second[j] << endl;
    }
  }
}
