#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> Vector(int n) {
  vector<T> v(n);
  for (T& x : v) cin >> x;
  return v;
}
void solution() {
  int n, x;
  cin >> n >> x;
  if (n <= 2) {
    cout << 1 << "\n";
    return;
  }
  int floor = 1;
  for (int i = 2; i < n; i += x) {
    floor++;
  }
  cout << floor << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solution();
  }
  return 0;
}
