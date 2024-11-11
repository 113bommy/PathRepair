#include <bits/stdc++.h>
using namespace std;
int arr[1001];
void initialise() {
  for (int i = 0; i < 1000; i++) {
    arr[i] = i;
  }
}
int root(int N) {
  while (arr[N] != N) {
    arr[N] = arr[arr[N]];
    N = arr[N];
  }
  return arr[N];
}
void dounion(int A, int B) {
  int rootA = root(A);
  int rootB = root(B);
  arr[rootA] = arr[rootB];
  return;
}
bool isunion(int A, int B) {
  int rootA = root(A);
  int rootB = root(B);
  if (rootA == rootB) {
    return true;
  }
  return false;
}
int main() {
  initialise();
  int N, M, u, v, w;
  cin >> N;
  int power[N + 1];
  long long int ans = 0;
  vector<pair<int, pair<int, int> > > edge;
  for (int i = 1; i <= N; i++) {
    cin >> power[i];
  }
  cin >> M;
  if (N == 1) {
    cout << "0";
    return 0;
  }
  for (int i = 1; i <= M; i++) {
    cin >> u >> v >> w;
    edge.push_back(make_pair(w, make_pair(u, v)));
  }
  sort(edge.begin(), edge.end());
  for (int i = 0; i < M; i++) {
    int node1 = edge[i].second.first;
    int node2 = edge[i].second.second;
    int weight = edge[i].first;
    if (!isunion(node1, node2)) {
      if (arr[node2] == node2) {
        dounion(node2, node1);
        ans += weight;
      }
    }
  }
  int temp = root(1);
  for (int i = 1; i <= N; i++) {
    if (root(i) != temp) {
      ans = -1;
    }
  }
  cout << ans;
  return 0;
}
