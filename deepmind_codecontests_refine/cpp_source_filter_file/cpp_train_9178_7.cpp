#include <bits/stdc++.h>
using namespace std;
mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
void debug(T value) {
  cerr << value << endl;
  ;
}
template <typename T, typename... Args>
void debug(T value, Args... arg) {
  cerr << value << " ";
  debug(arg...);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long double h, l;
  cin >> h >> l;
  cout << fixed << setprecision(15);
  cout << (h * h + l * l) / (2.0 * h);
  cout << endl;
  return 0;
}
