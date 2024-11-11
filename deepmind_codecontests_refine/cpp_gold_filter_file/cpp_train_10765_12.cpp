#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 1e5 + 7;
void print(int x) {
  if (x < 5)
    cout << "O-|";
  else
    cout << "-O|";
  if (x >= 5) x -= 5;
  int i = 0;
  for (; i < x; i += 1) cout << "O";
  cout << "-";
  for (; i < 4; i++) cout << "O";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  if (n == 0) {
    cout << "O-|-OOOO";
    return 0;
  }
  while (n) {
    print(n % 10);
    n /= 10;
    cout << '\n';
  }
  return 0;
}
