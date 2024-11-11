#include <bits/stdc++.h>
using namespace std;
const int mxx = 2e5 + 5;
int n;
vector<int> tr(mxx, 0);
stack<int> stk[26];
void update(int x, int val) {
  ++x;
  for (; x <= n; x += (x & (-x))) tr[x] += val;
}
int query(int x) {
  ++x;
  int sm = 0;
  for (; x; x -= (x & (-x))) sm += tr[x];
  return sm;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) stk[s[i] - 'a'].push(i);
  reverse(s.begin(), s.end());
  int res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int a = stk[s[i] - 'a'].top();
    stk[s[i] - 'a'].pop();
    update(a, 1);
    res += (i - a + query(a - 1));
  }
  cout << res << endl;
  return 0;
}
