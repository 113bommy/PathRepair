#include <bits/stdc++.h>
using namespace std;
char arr[1000][1001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int p = 0, idx = 0;
  for (int j = 0; j < l; ++j) {
    for (int i = idx; i < k; ++i) arr[i][j] = s[p++];
    while (arr[idx][j] != arr[k - 1][j]) ++idx;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j)
      if (!arr[i][j]) arr[i][j] = s[p++];
    cout << arr[i] << endl;
  }
  return 0;
}
