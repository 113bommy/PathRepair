#include <bits/stdc++.h>
using namespace std;
const int CHUNK = 1000;
const int N = 1e6;
const int CN = 1010;
vector<pair<pair<int, int>, int>> cols[CN];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int c = x / CHUNK;
    cols[c].push_back({{((c % 2) ? y : (-y)), x}, i + 1});
  }
  for (int col = 0; col < CN; col++) {
    sort(cols[col].begin(), cols[col].end());
    for (int i = 0; i < cols[col].size(); i++)
      cout << cols[col][i].second << " ";
  }
  cout << endl;
  return 0;
}
