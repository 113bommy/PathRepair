#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int>& a) {
  int n = a.size();
  stack<int> S;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0)
      S.push(i);
    else {
      a[i] = -a[i];
      stack<int> T;
      for (T.push(i); !T.empty(); S.pop()) {
        if (S.empty())
          return false;
        else if (a[S.top()] != a[T.top()])
          T.push(S.top());
        else {
          a[T.top()] = -a[T.top()];
          T.pop();
        }
      }
    }
  }
  while (!S.empty()) {
    stack<int> T;
    T.push(S.top());
    for (S.pop(); !T.empty(); S.pop()) {
      if (S.empty())
        return false;
      else if (a[S.top()] != a[T.top()])
        T.push(S.top());
      else {
        a[T.top()] = -a[T.top()];
        T.pop();
      }
    }
  }
  return true;
}
int main() {
  int n, m;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (scanf("%d", &m); m > 0; m--) {
    int x;
    scanf("%d", &x);
    a[x] = -a[x];
  }
  if (!solve(a))
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n; i++) printf(i == n - 1 ? "%d\n" : "%d ", a[i]);
  }
}
