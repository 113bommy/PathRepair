#include <bits/stdc++.h>
using namespace std;
bool comparison(pair<int, int> &a, pair<int, int> &b) { return a < b; }
typedef priority_queue<int, vector<int>, greater<int> > min_heap;
void do_this() {
  vector<string> arr(9);
  for (auto &s : arr) cin >> s;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (arr[i][j] == '1') arr[i][j] = '3';
    }
  }
  for (auto &s : arr) cout << s << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) do_this();
  return 0;
}
