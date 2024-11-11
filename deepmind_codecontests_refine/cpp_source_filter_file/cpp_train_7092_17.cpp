#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
vector<int> edges[100005];
bool lucky(int num) {
  for (; num > 0; num /= 10) {
    if (num % 10 != 4 and num % 10 != 7) {
      return false;
    }
  }
  return true;
}
bool visited[100005];
long long flood(int pos, int prev) {
  ;
  if (visited[pos]) return 0;
  visited[pos] = true;
  int out = 0;
  ;
  for (int i = 0; i < edges[pos].size(); i++) {
    out += flood(edges[pos][i], pos);
  }
  return out + 1;
}
int main(int argc, char** argv) {
  int nodenum;
  cin >> nodenum;
  int edgenum = 0;
  for (int i = 0; i < nodenum - 1; i++) {
    int a, b, dist;
    cin >> a >> b >> dist;
    a--;
    b--;
    if (!lucky(dist)) {
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
  }
  vector<long long> groups;
  for (int i = 0; i < nodenum; i++) {
    if (!visited[i]) {
      groups.push_back(flood(i, -1));
    }
  }
  int out = 0;
  for (int i = 0; i < groups.size(); i++) {
    out += groups[i] * (nodenum - groups[i]) * (nodenum - groups[i] - 1);
  }
  cout << out << "\n";
  return 0;
}
