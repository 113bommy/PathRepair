#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
int t, n;
char arr[N][N];
vector<pair<int, int>> ans;
void solve() {
  ans.clear();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }
  int zerocnt = 0, onecnt = 0, zerocnt2 = 0, onecnt2 = 0;
  if (arr[1][3] == '0')
    zerocnt++;
  else
    onecnt++;
  if (arr[2][2] == '0')
    zerocnt++;
  else
    onecnt++;
  if (arr[3][1] == '0')
    zerocnt++;
  else
    onecnt++;
  if (arr[1][2] == '0')
    zerocnt2++;
  else
    onecnt2++;
  if (arr[2][1] == '0')
    zerocnt2++;
  else
    onecnt2++;
  if ((zerocnt == 3 || onecnt == 3) && (zerocnt2 == 2 || onecnt2 == 2)) {
    if ((zerocnt == 3 && onecnt2 == 2) || (onecnt == 3 && zerocnt2 == 0)) {
      cout << 0 << "\n";
      return;
    } else {
      if (zerocnt == 3 && zerocnt2 == 2) {
        ans.push_back({1, 2});
        ans.push_back({2, 1});
      } else if (onecnt == 3 && onecnt2 == 2) {
        ans.push_back({1, 2});
        ans.push_back({2, 1});
      }
    }
  } else {
    if (zerocnt > onecnt) {
      if (zerocnt2 == 2) {
        if (arr[1][3] == '0') ans.push_back({1, 3});
        if (arr[2][2] == '0') ans.push_back({2, 2});
        if (arr[3][1] == '0') ans.push_back({3, 1});
      } else {
        if (arr[1][3] == '1') ans.push_back({1, 3});
        if (arr[2][2] == '1') ans.push_back({2, 2});
        if (arr[3][1] == '1') ans.push_back({3, 1});
        if (arr[1][2] == '0') ans.push_back({1, 2});
        if (arr[2][1] == '0') ans.push_back({2, 1});
      }
    } else if (onecnt > zerocnt) {
      if (onecnt2 == 2) {
        if (arr[1][3] == '1') ans.push_back({1, 3});
        if (arr[2][2] == '1') ans.push_back({2, 2});
        if (arr[3][1] == '1') ans.push_back({3, 1});
      } else {
        if (arr[1][3] == '0') ans.push_back({1, 3});
        if (arr[2][2] == '0') ans.push_back({2, 2});
        if (arr[3][1] == '0') ans.push_back({3, 1});
        if (arr[1][2] == '1') ans.push_back({1, 2});
        if (arr[2][1] == '1') ans.push_back({2, 1});
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto p : ans) cout << p.first << " " << p.second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
