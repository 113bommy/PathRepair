#include <bits/stdc++.h>
using namespace std;
vector<int> nodeNeighbour[100002];
bool isVisited[100002];
int color[100002], cnt;
void depthFirstSearch(int node) {
  isVisited[node] = true;
  for (int i = 0; i < nodeNeighbour[node].size(); i++) {
    int n = nodeNeighbour[node][i];
    if (color[node] == color[n]) {
      cnt++;
    }
    if (!isVisited[n]) {
      depthFirstSearch(n);
    }
  }
}
int main() {
  int vrtx;
  cin >> vrtx;
  for (int i = 2; i <= vrtx; i++) {
    int p;
    cin >> p;
    nodeNeighbour[p].push_back(i);
  }
  for (int i = 1; i <= vrtx; i++) {
    int k;
    cin >> k;
    color[i] = k;
  }
  depthFirstSearch(1);
  cout << vrtx - cnt << endl;
}
