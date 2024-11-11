#include <bits/stdc++.h>
using namespace std;
struct myp {
  int node;
  long long weight;
};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long count1;
int f[1008][1008];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int final[1000008];
int check[1000008];
int cost[1000008][2];
void Costi(int node, vector<myp> *edges) {
  check[node] = 1;
  long long min = INT_MAX;
  bool checkexist = false;
  for (int i = 0; i < edges[node].size(); i++) {
    if (check[edges[node][i].node] == 0) {
      Costi(edges[node][i].node, edges);
      if (cost[edges[node][i].node][1] - cost[edges[node][i].node][0] -
              edges[node][i].weight <
          min) {
        min = cost[edges[node][i].node][1] - cost[edges[node][i].node][0] -
              edges[node][i].weight;
        checkexist = true;
      }
      cost[node][0] += cost[edges[node][i].node][0] + 2 * edges[node][i].weight;
    }
  }
  if (checkexist) cost[node][1] = cost[node][0] + min;
  check[node] = 0;
}
int main() {
  int n;
  cin >> n;
  vector<myp> *edges;
  edges = new vector<myp>[n];
  int x, y;
  long long weight;
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    cin >> y >> weight;
    edges[x - 1].push_back(myp{y - 1, weight});
    edges[y - 1].push_back(myp{x - 1, weight});
  }
  Costi(0, edges);
  cout << cost[0][1];
}
