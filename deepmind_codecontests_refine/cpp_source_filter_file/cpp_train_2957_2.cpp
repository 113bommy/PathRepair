#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 5;
vector<int> adj[MAX];
int arr[MAX];
inline bool reach(int a, int b) {
  return binary_search(adj[a].begin(), adj[a].end(), b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  for (int i = 0; i < n; i++) arr[i] = i + 1;
  while (clock() <= 1300) {
    random_shuffle(arr, arr + n);
    arr[n] = arr[n - 1];
    bool okay = 1;
    for (int i = 0; i < m && okay; i++)
      if (reach(arr[i], arr[i + 1])) okay = 0;
    if (okay) {
      for (int i = 0; i < m; i++) cout << arr[i] << " " << arr[i + 1] << "\n";
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
