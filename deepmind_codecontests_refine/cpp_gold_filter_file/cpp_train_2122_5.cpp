#include <bits/stdc++.h>
using namespace std;
vector<list<long long int> > adj(1000), Adj(1000);
long long int visited[1000];
void dfs(long long int u, long long int temp) {
  visited[u] = temp;
  list<long long int>::iterator iter;
  for (iter = adj[u].begin(); iter != adj[u].end(); iter++) {
    if (visited[*iter] == 0) {
      dfs(*iter, temp);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  long long int n, m;
  cin >> n >> m;
  long int flag = 0;
  for (long int i = 1; i <= n; i++) {
    long int counter;
    cin >> counter;
    if (counter == 0) {
      flag++;
    }
    while (counter--) {
      long long int a;
      cin >> a;
      Adj[a].push_back(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    list<long long int>::iterator iter, it;
    for (iter = Adj[i].begin(); iter != Adj[i].end(); iter++) {
      for (it = Adj[i].begin(); it != Adj[i].end(); it++) {
        adj[*iter].push_back(*it);
        adj[*it].push_back(*iter);
      }
    }
  }
  long long int check = 1;
  for (long int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      dfs(i, check);
      check++;
    }
  }
  if (flag == n) {
    check = n;
  } else {
    check = check - 2;
  }
  cout << check << endl;
  return 0;
}
