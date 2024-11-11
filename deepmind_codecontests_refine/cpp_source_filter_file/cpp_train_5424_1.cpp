#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(601);
vector<int> unvisited, even, odd;
int d[601], parent[601];
bool visited[601];
void RemoveFromUnvisited(int v) {
  int i = 0;
  for (; i < unvisited.size() && unvisited[i] != v; ++i)
    ;
  unvisited.erase(unvisited.begin() + i);
}
void PrintQueryOrAnswer(char c, vector<int> &A) {
  printf("%c %lu\n", c, A.size());
  for (auto x : A) {
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
}
int Query(vector<int> &A, int s = 0) {
  if (s) {
    A.push_back(s);
  }
  PrintQueryOrAnswer('?', A);
  if (s) {
    A.pop_back();
  }
  int m;
  scanf("%d", &m);
  return m;
}
int NextChild(int i, vector<int> A) {
  if (A.size() == 0) {
    return 0;
  }
  int m1 = Query(A, i);
  if (m1 == 0) {
    return 0;
  }
  if (A.size() == 1) {
    return A.back();
  }
  int m2 = Query(A);
  if (m2 == m1) {
    return 0;
  }
  int j = NextChild(i, vector<int>(A.begin(), A.begin() + (A.size() / 2)));
  if (j == 0) {
    j = NextChild(i, vector<int>(A.begin() + (A.size() / 2), A.end()));
  }
  return j;
}
void AddEdge(int i, int j) {
  adj[i].push_back(j);
  adj[j].push_back(i);
}
void AddEdgeDFS(int i, bool markEvenOdd) {
  RemoveFromUnvisited(i);
  if (markEvenOdd) {
    if (d[i]) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  for (int j = NextChild(i, unvisited); j > 0; j = NextChild(i, unvisited)) {
    AddEdge(i, j);
    if (markEvenOdd) {
      d[j] = 1 - d[i];
    }
    AddEdgeDFS(j, markEvenOdd);
  }
}
pair<int, int> BipartiteDFS(int i, int p) {
  parent[i] = p;
  d[i] = 1 + d[p];
  visited[i] = 1;
  pair<int, int> ans = make_pair(0, 0);
  for (auto j : adj[i]) {
    if (j == p) {
      continue;
    }
    if (visited[j]) {
      if ((d[i] - d[j]) % 2 == 0 && d[i] > d[j]) {
        return make_pair(i, j);
      }
      continue;
    }
    ans = max(ans, BipartiteDFS(j, i));
  }
  return ans;
}
void AddEdges(vector<int> v, bool markEvenOdd) {
  unvisited = vector<int>(v);
  while (unvisited.size()) {
    AddEdgeDFS(unvisited.back(), markEvenOdd);
  }
}
int main() {
  int n;
  vector<int> V;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    V.push_back(i);
  }
  AddEdges(V, true);
  AddEdges(even, false);
  AddEdges(odd, false);
  pair<int, int> p = make_pair(0, 0);
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) {
      continue;
    }
    p = max(p, BipartiteDFS(i, 0));
  }
  int u, v;
  tie(u, v) = p;
  vector<int> ans;
  if (u == 0) {
    for (int i = 1; i <= n; ++i) {
      if (d[i]) {
        ans.push_back(i);
      }
    }
  } else {
    for (; u != parent[v]; u = parent[u]) {
      ans.push_back(u);
    }
  }
  PrintQueryOrAnswer(v ? 'N' : 'Y', ans);
  return 0;
}
