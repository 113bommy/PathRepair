#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void maximize(T &x, U y) {
  if (x < y) x = y;
}
template <class T, class U>
void minimize(T &x, U y) {
  if (x > y) x = y;
}
template <class T>
T Abs(T x) {
  return (x < 0 ? -x : x);
}
template <class T>
T safe_sqrt(T x) {
  return sqrt(max(x, (T)0));
}
template <class T, class U, class V>
T addmod(T x, U k, V MOD) {
  return ((x + k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T submod(T x, U k, V MOD) {
  return ((x - k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T mul(T x, U y, V MOD) {
  return (long long)x * y % MOD;
}
namespace task {
const int N = 5e5 + 5;
int next[N], prev[N];
pair<int, int> pos[N];
char s[N];
int n, m, cur;
stack<int> stk;
int painted[N];
void solve() {
  scanf("%d%d%d", &n, &m, &cur);
  scanf("%s", s + 1);
  for (int i = 1; i < n; ++i) next[i] = i + 1;
  for (int i = 2; i <= n; ++i) prev[i] = i - 1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(')
      stk.push(i);
    else {
      while (!stk.empty() and s[stk.top()] == '(') {
        pos[stk.top()] = pos[i] = make_pair(stk.top(), i);
        stk.pop();
        break;
      }
    }
  }
  while (m--) {
    char op;
    scanf(" %c", &op);
    if (op == 'L')
      cur = prev[cur];
    else if (op == 'R')
      cur = next[cur];
    else {
      int l, r;
      l = pos[cur].first;
      r = pos[cur].second;
      painted[l]++, painted[r + 1]--;
      next[prev[l]] = next[r];
      prev[next[r]] = prev[l];
      if (!next[r])
        cur = prev[l];
      else
        cur = next[r];
    }
  }
  for (int i = 2; i <= n; ++i) painted[i] += painted[i - 1];
  for (int i = 1; i <= n; ++i)
    if (!painted[i]) printf("%c", s[i]);
}
}  // namespace task
int main(void) { task::solve(); }
