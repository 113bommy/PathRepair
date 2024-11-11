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
int n, m, picked[122];
pair<int, int> order[22];
int dp[(1 << 20) + 10];
bool visit[(1 << 20) + 10];
int rec(int pos, int mask) {
  if (pos >= m) return 0;
  int &ret = dp[mask];
  if (visit[mask] == true) return ret;
  visit[mask] = true;
  if (order[pos].second == 1)
    ret = -1 * (1 << 29);
  else
    ret = (1 << 29);
  if (order[pos].first == 1) {
    for (int j = 0; j < m; j++)
      if ((mask & (1 << j)) == 0) {
        if (order[pos].second == 1)
          ret = max(ret, rec(pos + 1, mask | (1 << j)) + picked[pos]);
        else
          ret = min(ret, rec(pos + 1, mask | (1 << j)) - picked[pos]);
      }
  } else {
    for (int j = 0; j < m; j++)
      if ((mask & (1 << j)) == 0) {
        if (order[pos].second == 1)
          ret = max(ret, rec(pos + 1, mask | (1 << j)));
        else
          ret = min(ret, rec(pos + 1, mask | (1 << j)));
      }
  }
  return ret;
}
int main(void) {
  int var;
  char arr[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &picked[i]);
  sort(picked, picked + n);
  reverse(picked, picked + n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s %d", arr, &var);
    if (arr[0] == 'p')
      order[i] = make_pair(1, var);
    else
      order[i] = make_pair(0, var);
  }
  printf("%d\n", rec(0, 0));
  return 0;
}
