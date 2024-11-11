#include <bits/stdc++.h>
const long double pi = 3.141592654;
using namespace std;
int n, k;
int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};
bool valid(int r, int c) { return r >= 0 && c >= 0 && r < n && c < n; }
char grid[120][120];
bool vis[100074];
vector<int> initial;
vector<vector<int>> graph;
int parent[100074];
void topological_sort(int student) {
  vis[student] = 1;
  for (auto child : graph[student]) {
    if (!vis[child]) topological_sort(child);
  }
  initial.push_back(student);
}
int main() {
  long long n;
  cin >> n;
  if (n == 2) {
    cout << 2;
  } else {
    if (n % 2 == 0)
      cout << 2;
    else
      cout << 1;
  }
}
