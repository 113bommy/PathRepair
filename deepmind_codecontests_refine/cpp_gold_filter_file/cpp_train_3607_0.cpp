#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 11;
char s[N] = {0}, t[N] = {0};
vector<int> count(const char* p) {
  vector<int> c(26, 0);
  for (int i = 0; p[i] != '\0'; i++) c[p[i] - 'a']++;
  return c;
}
int position(int n, int i) { return i & 1 ? (n - i - 1) >> 1 : (n + i) >> 1; }
void modify(int n, int x, vector<int>& ans) {
  if (x == 0) return;
  static int b[N];
  for (int i = 0; i < n; i++) b[i] = s[i];
  for (int i = 0; i < x; i++) s[i] = b[n - i - 1];
  for (int i = 0; i < n - x; i++) s[i + x] = b[i];
  if (!ans.empty() && ans.back() == 6 && x == 6)
    ans.pop_back();
  else
    ans.push_back(x);
}
vector<int> solve(int n) {
  vector<int> ans;
  if (count(s) != count(t)) return ans;
  for (int i = 0; i < n; i++) {
    int p = position(n, i), q;
    for (q = i; s[q] != t[p]; q++)
      ;
    int la = q - i, lb = n - q - 1;
    modify(n, lb + 1, ans);
    modify(n, la, ans);
    modify(n, n, ans);
  }
  if (~n & 1) modify(n, n, ans);
  return ans;
}
int main() {
  int n;
  scanf("%d%s%s", &n, s, t);
  vector<int> ans = solve(n);
  if (ans.empty())
    printf("-1\n");
  else {
    n = ans.size();
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf(i == n - 1 ? "%d\n" : "%d ", ans[i]);
  }
}
