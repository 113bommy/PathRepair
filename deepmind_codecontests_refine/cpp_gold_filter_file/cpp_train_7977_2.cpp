#include <bits/stdc++.h>
using namespace std;
int outdegree[1050], leafCount[1050];
vector<int> arr[1050];
bool dfs(int node, int par = -1) {
  int size = 0;
  for (int child : arr[node]) {
    if (child != par) {
      if (!dfs(child, node)) {
        return false;
      }
    }
    if (outdegree[child] == 0) {
      size++;
    }
  }
  if (size >= 3 || (size == 0 && arr[node].size() == 0)) {
    return true;
  } else {
    return false;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a;
    outdegree[a]++;
    arr[a].push_back(i + 1);
  }
  if (dfs(1)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
