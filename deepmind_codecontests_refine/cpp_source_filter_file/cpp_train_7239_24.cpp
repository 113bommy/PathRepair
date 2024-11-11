#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v1, v2;
  int min, max, price;
};
int maxSum = -1;
Edge edges[6][6];
void go(int from, int to, int n, int sum, vector<int>& flow) {
  if (from == n) {
    for (int i = (0); i < ((n - 1)); ++i)
      if (flow[i] != 0) return;
    maxSum = max(maxSum, sum);
    return;
  }
  if (to == n) {
    go(from + 1, from + 2, n, sum, flow);
    return;
  }
  for (int toFlow = (edges[from][to].min); toFlow < (edges[from][to].max + 1);
       ++toFlow)
    if (flow[from] >= toFlow) {
      flow[from] -= toFlow;
      flow[to] += toFlow;
      go(from, to + 1, n,
         sum + edges[from][to].price * (toFlow != 0) + toFlow * toFlow, flow);
      flow[to] -= toFlow;
      flow[from] += toFlow;
    }
}
int main() {
  int n;
  cin >> n;
  for (int i = (0); i < ((n * (n - 1) / 2)); ++i) {
    Edge edge;
    cin >> edge.v1 >> edge.v2 >> edge.min >> edge.max >> edge.price;
    --edge.v1;
    --edge.v2;
    edges[edge.v1][edge.v2] = edge;
  }
  for (int result = (0); result < ((6)); ++result) {
    vector<int> flow(n);
    flow[0] = result;
    go(0, 1, n, 0, flow);
    if (maxSum != -1) {
      cout << result << " " << maxSum << endl;
      return 0;
    }
  }
  cout << "-1 -1\n";
  return 0;
}
