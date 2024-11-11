#include <bits/stdc++.h>
using namespace std;
template <typename T>
T &parse(T &t) {
  cin >> t;
  return t;
}
template <typename T, typename... Args>
void parse(T &t, Args &...args) {
  parse(t);
  parse(args...);
}
template <typename T>
void print(T t) {
  cout << t << "\n";
}
template <typename T>
void print(T &t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void print(T &t, Args &...args) {
  cout << t << " ";
  print(args...);
}
int solve(size_t n) { return ((n * (n + 1)) / 2 % 2); }
int main() {
  int n, k;
  parse(n, k);
  print(solve(n));
}
