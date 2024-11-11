#include <bits/stdc++.h>
using namespace std;
void read(char& a) {
  do scanf("%c", &a);
  while (isspace(a));
}
void write(const char& a) { printf("%c", a); }
char BUF[1234560];
void read(string& a) {
  scanf("%s", BUF);
  a = string(BUF);
}
void write(const string& a) { printf("%s", a.c_str()); }
void read(int& a) { scanf("%d", &a); }
void write(const int& a) { printf("%d", a); }
void read(long long& a) { scanf("%I64d", &a); }
void write(const long long& a) { printf("%I64d", a); }
void read(double& a) { scanf("%lf", &a); }
void write(const double& a) { printf("%lf", a); }
void read(long double& a) { scanf("%Lf", &a); }
void write(const long double& a) { printf("%Lf", a); }
void read(pair<int, int>& a) { scanf("%d%d", &a.first, &a.second); }
void write(const pair<int, int>& a) { printf("%d %d", a.first, a.second); }
template <template <typename T, typename A = allocator<T> > class C, class T>
void read(C<T>& a) {
  int sz = a.size();
  for (int i = 0; i < sz; ++i) read(a[i]);
}
template <template <typename T, typename A = allocator<T> > class C, class T>
void write(const C<T>& a) {
  int sz = a.size();
  if (sz != 0) write(a[0]);
  for (int i = 1; i < sz; ++i) {
    write(' ');
    write(a[i]);
  }
}
template <typename T1, typename T2>
void read(T1& t1, T2& t2) {
  read(t1);
  read(t2);
}
template <typename T1, typename T2>
void write(const T1& t1, const T2& t2) {
  write(t1);
  write(' ');
  write(t2);
}
template <typename T1, typename T2, typename T3>
void read(T1& t1, T2& t2, T3& t3) {
  read(t1);
  read(t2);
  read(t3);
}
template <typename T1, typename T2, typename T3, typename T4>
void read(T1& t1, T2& t2, T3& t3, T4& t4) {
  read(t1);
  read(t2);
  read(t3);
  read(t4);
}
template <typename T1, typename T2, typename T3>
void write(const T1& t1, const T2& t2, const T3& t3) {
  write(t1);
  write(' ');
  write(t2);
  write(' ');
  write(t3);
}
template <template <typename T, typename A = allocator<T> > class C, class T>
void sort(C<T>& a) {
  sort((a).begin(), (a).end());
}
template <typename T>
int sz(const T& a) {
  return int(a.size());
}
int main() {
  int t;
  read(t);
  for (int _VARIABLE{(t) + 1}; --_VARIABLE;) {
    int first, second, a, b;
    read(first, second, a, b);
    int p{second - first}, q{a + b};
    write(p % q ? -1 : p / q), write('\n');
  }
}
