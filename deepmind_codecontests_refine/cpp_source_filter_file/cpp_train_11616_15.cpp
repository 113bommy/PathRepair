#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<vector<int>> adjList, C;
vector<long long> r_solve(int node) {
  long long curr_val, max_val, max_sum;
  curr_val = max_val = max_sum = 0;
  curr_val = A[node];
  max_val = max_sum = (long long)10e-16;
  vector<long long> S;
  for (int child : C[node]) {
    vector<long long> cV = r_solve(child);
    curr_val += cV[0];
    max_sum = max(max_sum, cV[2]);
    max_val = max(max_val, cV[1]);
    S.push_back(cV[1]);
  }
  max_val = max(max_val, curr_val);
  sort(S.rbegin(), S.rend());
  if (S.size() >= 2) max_sum = max(max_sum, S[0] + S[1]);
  return vector<long long>{curr_val, max_val, max_sum};
}
int main() {
  int n;
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  adjList.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  C.resize(n);
  deque<int> Q{0};
  bool isPath = true;
  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop_front();
    for (int next : adjList[curr]) {
      if (C[next].size()) continue;
      C[curr].push_back(next);
      Q.push_back(next);
    }
    if (C[curr].size() > 1) isPath = false;
  }
  vector<long long> result = r_solve(0);
  cout << (isPath ? "Impossible" : to_string(result[2])) << endl;
}
