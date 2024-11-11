#include <bits/stdc++.h>
using namespace std;
const int MAXn = 100 * 1000 + 1000;
int n, a[MAXn], b[MAXn], a_ans[MAXn], b_ans[MAXn];
pair<int, int> s[MAXn];
int saghf(int x, int y) {
  if (x % y == 0) return (int)x / y;
  return ((int)x / y + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(s, s + n);
  for (int i = 1; i <= saghf(n, 3); ++i) {
    a[i] = s[i].first;
    b[i] = 0;
  }
  for (int i = saghf(n, 3) + 1; i <= 2 * saghf(n, 3); ++i) {
    b[i] = s[i].first;
    a[i] = 0;
  }
  int j = saghf(n, 3) - 1;
  for (int i = 2 * saghf(n, 3) + 1; i <= n; ++i) {
    b[i] = j--;
    a[i] = s[i].first - b[i];
  }
  for (int i = 1; i <= n; ++i) {
    a_ans[s[i].second] = a[i];
    b_ans[s[i].second] = b[i];
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) cout << a_ans[i] << " ";
  cout << endl;
  for (int i = 1; i <= n; ++i) cout << b_ans[i] << " ";
  cout << endl;
}
