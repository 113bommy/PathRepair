#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
struct P {
  int first, second, z;
  P(int first = 0, int second = 0, int z = 0)
      : first(first), second(second), z(z) {}
  void U() { second++; }
  void D() { second--; }
  void F() { z++; }
  void B() { z--; }
  void R() { first++; }
  void L() { first--; }
};
deque<P> q;
int mat[50][50][50];
int main() {
  int n;
  cin >> n;
  if (n == 1) return puts("1"), 0;
  if (n == 2) return puts("1 2\n4 3\n8 7\n5 6"), 0;
  P A = P(0, 0, 0);
  q.push_back(A);
  P B = A;
  B.D();
  q.push_back(B);
  B.B();
  q.push_back(B);
  B.U();
  q.push_back(B);
  B.L();
  q.push_back(B);
  B.D();
  q.push_back(B);
  B.F();
  q.push_back(B);
  B.U();
  q.push_back(B);
  B.L();
  q.push_back(B);
  B.B();
  q.push_back(B);
  B.D();
  q.push_back(B);
  B.F();
  q.push_back(B);
  for (int m = 3; m <= n; m++) {
    if (m & 1) {
      A.F();
      q.push_front(A);
      for (int j = 1; j < m; j++) A.L(), q.push_front(A);
      A.U();
      q.push_front(A);
      for (int j = 2; j < m; j++) A.R(), q.push_front(A);
      for (int i = 0; i < m >> 1; i++) {
        A.B(), q.push_front(A);
        for (int j = 2; j < m; j++) A.L(), q.push_front(A);
        A.B(), q.push_front(A);
        for (int j = 2; j < m; j++) A.R(), q.push_front(A);
      }
      A.R();
      q.push_front(A);
      for (int j = 1; j < m; j++) A.F(), q.push_front(A);
      B.F();
      q.push_back(B);
      for (int j = 3; j < m; j++) B.U(), q.push_back(B);
      for (int j = 1; j < m; j++) B.R(), q.push_back(B);
      for (int i = 1; i < m >> 1; i++) {
        B.D(), q.push_back(B);
        for (int j = 2; j < m; j++) B.L(), q.push_back(B);
        B.D(), q.push_back(B);
        for (int j = 2; j < m; j++) B.R(), q.push_back(B);
      }
      B.D();
      q.push_back(B);
      for (int j = 2; j < m; j++) B.L(), q.push_back(B);
      for (int i = 0; i < m >> 1; i++) {
        B.B(), q.push_back(B);
        for (int j = 2; j < m; j++) B.R(), q.push_back(B);
        B.B(), q.push_back(B);
        for (int j = 2; j < m; j++) B.L(), q.push_back(B);
      }
      B.L();
      q.push_back(B);
      for (int j = 1; j < m; j++) B.F(), q.push_back(B);
    } else {
      A.F();
      q.push_front(A);
      for (int j = 1; j < m; j++) A.D(), q.push_front(A);
      A.R();
      q.push_front(A);
      for (int j = 1; j < m; j++) A.B(), q.push_front(A);
      A.U();
      q.push_front(A);
      for (int j = 1; j < m; j++) A.F(), q.push_front(A);
      for (int i = 1; i < m >> 1; i++) {
        A.U();
        q.push_front(A);
        for (int j = 1; j < m; j++) A.B(), q.push_front(A);
        A.U();
        q.push_front(A);
        for (int j = 1; j < m; j++) A.F(), q.push_front(A);
      }
      B.F();
      q.push_back(B);
      for (int j = 3; j < m; j++) B.R(), q.push_back(B);
      B.U();
      q.push_back(B);
      for (int j = 3; j < m; j++) B.L(), q.push_back(B);
      for (int i = 1; i < m >> 1; i++) {
        B.U();
        q.push_back(B);
        for (int j = 3; j < m; j++) B.R(), q.push_back(B);
        B.U();
        q.push_back(B);
        for (int j = 3; j < m; j++) B.L(), q.push_back(B);
      }
      B.L();
      q.push_back(B);
      for (int j = 1; j < m; j++) B.B(), q.push_back(B);
      B.D();
      q.push_back(B);
      for (int j = 1; j < m; j++) B.F(), q.push_back(B);
      for (int i = 1; i < m >> 1; i++) {
        B.D();
        q.push_back(B);
        for (int j = 1; j < m; j++) B.B(), q.push_back(B);
        B.D();
        q.push_back(B);
        for (int j = 1; j < m; j++) B.F(), q.push_back(B);
      }
    }
  }
  int mnx = 1e9, mny = 1e9, mnz = 1e9;
  vector<P> ans;
  int m = n * n * n;
  for (int i = 0; i < m; i++) ans.push_back(q.front()), q.pop_front();
  for (P p : ans) smin(mnx, p.first), smin(mny, p.second), smin(mnz, p.z);
  for (int i = 0; i < m; i++)
    mat[ans[i].first - mnx][ans[i].second - mny][ans[i].z - mnz] = i + 1;
  for (int i = 0; i < n; i++, puts(""))
    for (int j = 0; j < n; j++, puts(""))
      for (int k = 0; k < n; k++) {
        printf("%d ", mat[i][j][k]);
      }
  return 0;
}
