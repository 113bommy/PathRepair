#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void pp(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename... T>
void po(T... args) {
  ((cout << args << " "), ...);
  cout << "";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  for (int tt = 1; tt <= test; tt++) {
    long long int n, k;
    cin >> n >> k;
    long long int tot = (n * (n - 1)) / 2;
    if (k >= tot) {
      cout << ("no solution");
      return 0;
    }
    for (long long int i = 0; i < n; i++) {
      pp(0, i);
    }
  }
  return 0;
}
