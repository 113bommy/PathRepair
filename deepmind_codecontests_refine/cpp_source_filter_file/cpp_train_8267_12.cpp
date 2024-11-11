#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
int BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
vector<pair<int, int> > v[100000];
bool blocked[100000];
int dfs(int now) {
  stack<int> notConnected;
  int to, id, last;
  for (int i = 0; i < (int)v[now].size(); i++) {
    to = v[now][i].first;
    id = v[now][i].second;
    if (blocked[id]) continue;
    blocked[id] = true;
    int last = dfs(to);
    if (last == 0)
      notConnected.push(to);
    else
      printf("%d %d %d\n", now, to, last);
  }
  while ((int)notConnected.size() > 1) {
    to = notConnected.top();
    notConnected.pop();
    last = notConnected.top();
    notConnected.pop();
    printf("%d %d %d\n", now, to, last);
  }
  if ((int)notConnected.size())
    return notConnected.top();
  else
    return 0;
}
int main(void) {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    v[a].push_back(make_pair(b, i));
    v[b].push_back(make_pair(a, i));
  }
  if (m % 2)
    puts("No solution");
  else
    dfs(1);
  return 0;
}
