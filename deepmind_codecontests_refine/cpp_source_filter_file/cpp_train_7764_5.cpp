#include <bits/stdc++.h>
using namespace std;
long long n, Q, start;
int max_len;
string s;
vector<int> cur;
void solve() {
  while (start > 0) {
    cur.push_back(start % 2);
    start /= 2;
  }
  int j;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L' || s[i] == 'R') {
      j = 0;
      while (j < cur.size() && cur[j] == 0) j++;
      if (j > 0) {
        if (s[i] == 'L') {
          swap(cur[j], cur[j - 1]);
        } else {
          cur[j - 1] = 1;
        }
      }
      while (!cur.empty() && cur.back() == 0) cur.pop_back();
    } else {
      j = 0;
      while (j < cur.size() && cur[j] == 0) j++;
      if (j == cur.size() - 1 && cur.size() == max_len) continue;
      if (j == cur.size() - 1 && cur.size() < max_len) {
        cur.push_back(1);
      }
      cur[j] = 0;
      cur[j + 1] = 1;
    }
  }
  long long foo = 1, res = 0;
  for (int i = 0; i < cur.size(); i++) {
    res += foo * cur[i];
    foo *= 2;
  }
  cur.clear();
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> Q;
  long long foo = 1;
  max_len = 1;
  while (foo < n) {
    foo *= 2;
    max_len++;
  }
  max_len--;
  for (int i = 1; i <= Q; i++) {
    cin >> start >> s;
    solve();
  }
}
