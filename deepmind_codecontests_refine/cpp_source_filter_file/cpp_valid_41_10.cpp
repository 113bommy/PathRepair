#include <bits/stdc++.h>
const unsigned int M = 1000000007;
using namespace std;
void solve() {
  int n;
  cin >> n;
  int q;
  cin >> q;
  string second;
  cin >> second;
  string s1[] = {"abc", "acb", "bac", "bca", "cba", "cab"};
  vector<vector<int> > arr(6, vector<int>(n + 1));
  for (int i = 1; i < n + 1; i += 1) {
    if (second[i - 1] != s1[0][i % 3])
      arr[0][i] = arr[0][i - 1] + 1;
    else
      arr[0][i] = arr[0][i - 1];
    if (second[i - 1] != s1[1][i % 3])
      arr[1][i] = arr[1][i - 1] + 1;
    else
      arr[1][i] = arr[1][i - 1];
    if (second[i - 1] != s1[2][i % 3])
      arr[2][i] = arr[2][i - 1] + 1;
    else
      arr[2][i] = arr[2][i - 1];
    if (second[i - 1] != s1[3][i % 3])
      arr[3][i] = arr[3][i - 1] + 1;
    else
      arr[3][i] = arr[3][i - 1];
    if (second[i - 1] != s1[4][i % 3])
      arr[4][i] = arr[4][i - 1] + 1;
    else
      arr[4][i] = arr[4][i - 1];
    if (second[i - 1] != s1[5][i % 3])
      arr[5][i] = arr[5][i - 1] + 1;
    else
      arr[5][i] = arr[5][i - 1];
  }
  int a, b;
  for (int i = 0; i < q; i += 1) {
    cin >> a >> b;
    int min = arr[0][b] - arr[0][a - 1];
    for (int i = 1; i < 6; i += 1) {
      if (arr[1][b] - arr[1][a - 1] < min) min = arr[1][b] - arr[1][a - 1];
    }
    cout << min << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
