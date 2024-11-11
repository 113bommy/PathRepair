#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int INF = 1000000000;
const int BS = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
stack<pair<int, int> > st1[5];
stack<pair<int, int> > st2[5];
int get1(int num) {
  if (st1[num].empty()) return 0;
  return st1[num].top().first;
}
int get2(int num) {
  if (st2[num].empty()) return 0;
  return st2[num].top().first;
}
int getmax(int num) { return max(get1(num), get2(num)); }
void push1(int num, int x) { st1[num].push(make_pair(max(x, get1(num)), x)); }
void push2(int num, int x) { st2[num].push(make_pair(max(x, get2(num)), x)); }
void pop(int num) {
  if (st2[num].empty()) {
    while (!st1[num].empty()) {
      push2(num, st1[num].top().second);
      st1[num].pop();
    }
  }
  st2[num].pop();
}
int main() {
  int n, m, k;
  int j;
  int i;
  scanf("%d%d%d", &n, &m, &k);
  static int a[NMAX][5];
  for (i = 1; i <= n; i++) {
    for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  }
  int ans = 0;
  int cur;
  int l = 1;
  int ml, mr;
  int res[5] = {0};
  for (i = 1; i <= n; i++) {
    for (j = 0; j < m; j++) {
      push1(j, a[i][j]);
    }
    cur = 0;
    for (j = 0; j < m; j++) cur += getmax(j);
    while (cur > k) {
      cur = 0;
      for (j = 0; j < m; j++) {
        pop(j);
        cur += getmax(j);
      }
      l++;
    }
    if (cur <= k) {
      if (ans < i - l + 1) {
        ans = i - l + 1;
        for (j = 0; j < m; j++) {
          res[j] = getmax(j);
        }
      }
    }
  }
  for (j = 0; j < m; j++) {
    cout << res[j] << " ";
  }
  cout << endl;
  return 0;
}
