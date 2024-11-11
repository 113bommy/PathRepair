#include <bits/stdc++.h>
using namespace std;
template <typename... T>
inline void input(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
inline void print(T &&...args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
int solve(int r, int b, int g) {
  return r >= 0 && b >= 0 && g >= 0 ? r / 3 + b / 3 + g / 3 : -1000;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int r, b, g;
  input(r, b, g);
  print(max(max(solve(r, b, g), 1 + solve(r - 1, b - 1, g - 1)),
            2 + solve(r - 2, b - 2, g - 2)));
  return 0;
}
