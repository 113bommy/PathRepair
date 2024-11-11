#include <bits/stdc++.h>
template <typename T>
T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
using arr = std::vector<T>;
template <typename T>
struct View {
  size_t size, off;
  T* data;
  T& operator[](size_t i) { return data[i * off]; }
};
template <typename T>
struct Mtx {
  size_t n, m;
  Mtx(size_t _n, size_t _m) : n(_n), m(_m), data(_n * _m) {}
  T* operator[](size_t i) { return &data[i * m]; }
  arr<T> data;
  View<T> row(size_t i) { return {m, 1, &data[m * i]}; }
  View<T> col(size_t i) { return {n, m, &data[i]}; }
};
void show(Mtx<int>& m) {
  for (int i = 0; i < m.n; ++i) {
    for (int j = 0; j < m.m; ++j) printf("%d ", m[i][j]);
    puts("");
  }
}
void show(arr<int>& v) {
  for (int& x : v) printf("%d ", x);
  puts("");
}
template <typename T>
struct Cmp {
  View<T> view;
  bool operator()(int i, int j) { return view[i] < view[j]; }
};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Mtx<int> A(n, m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &A[i][j]);
  Mtx<int> R(n, m);
  arr<int> Rc(n, 0);
  arr<int> X(m);
  for (int j = 0; j < m; ++j) X[j] = j;
  for (int i = 0; i < n; ++i) {
    Cmp<int> cmp{A.row(i)};
    std::sort(X.begin(), X.end(), cmp);
    for (int j = 0; j < m; ++j) {
      if (j && cmp(X[j - 1], X[j])) Rc[i]++;
      R[i][X[j]] = Rc[i];
    }
    Rc[i]++;
  }
  Mtx<int> Q(n, m);
  X.resize(n);
  for (int i = 0; i < n; ++i) X[i] = i;
  for (int j = 0; j < m; ++j) {
    Cmp<int> cmp{A.col(j)};
    std::sort(X.begin(), X.end(), cmp);
    int c = 0;
    for (int i = 0; i < n; ++i)
      if (i && cmp(X[i - 1], X[i])) c++;
    c++;
    int d = 0;
    for (int i = 0; i < n; ++i) {
      if (i && cmp(X[i - 1], X[i])) d++;
      Q[X[i]][j] = max(d, R[X[i]][j]) + max(c - d, Rc[X[i]] - R[X[i]][j]);
    }
  }
  show(Q);
  return 0;
}
