#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  unordered_map<int, int> umap;
  for (int i = 0; i < n; i++) {
    umap[arr[i]]++;
  }
  int pockets = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (umap[arr[i]] < pockets) {
      pockets = umap[arr[i]];
    }
  }
  if (n == 1) {
    cout << 1 << endl;
  } else {
    cout << pockets << endl;
  }
  return 0;
}
