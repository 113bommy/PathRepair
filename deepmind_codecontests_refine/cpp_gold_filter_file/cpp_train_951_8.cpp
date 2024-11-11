#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
deque<int> q;
vector<char> ans, k1, k2, k;
void g_left(int v) {
  int x = v;
  deque<int> t = q;
  x = t.front();
  t.pop_front();
  k1.push_back('L');
  while (t.size() > 0) {
    int a = t.front(), b = t.back();
    if (a > x) {
      k1.push_back('L');
      x = a;
      t.pop_front();
    } else
      return;
  }
  return;
}
void g_right(int v) {
  int x = v;
  deque<int> t = q;
  x = t.back();
  t.pop_back();
  k2.push_back('R');
  while (t.size() > 0) {
    int a = t.front(), b = t.back();
    if (b > x) {
      k2.push_back('R');
      x = b;
      t.pop_back();
    } else
      return;
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    q.push_back(t);
  }
  int x = -1;
  while (q.size() > 0) {
    int a = q.front();
    int b = q.back();
    if (a < b && x < a || a > x && b <= x) {
      ans.push_back('L');
      x = a;
      q.pop_front();
    } else if (b < a && x < b || b > x && a <= x) {
      ans.push_back('R');
      x = b;
      q.pop_back();
    } else if (a == b && x < a) {
      g_left(x);
      g_right(x);
      if (k1.size() > k2.size()) {
        for (char i : k1) ans.push_back(i);
      } else {
        for (char i : k2) ans.push_back(i);
      }
      cout << ans.size() << endl;
      for (auto i : ans) cout << i;
      return 0;
    } else
      break;
  }
  if (q.size() == 1 && x < q.back()) ans.push_back('R');
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i];
  }
}
