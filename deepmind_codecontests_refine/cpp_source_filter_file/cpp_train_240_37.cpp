#include <bits/stdc++.h>
using namespace std;
const string Fi = "First\n", Se = "Second\n";
bool solve(long long a, long long b) {
  if (a == 0 || b == 0) return false;
  if (a > b) swap(a, b);
  if (!solve(b % a, a)) return true;
  long long x = b / a;
  if (a & 1) return (x ^ 1) & 1;
  return ((x % (a - 1)) ^ 1) & 1;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T-- > 0) {
    long long a, b;
    cin >> a >> b;
    if (solve(a, b))
      cout << Fi;
    else
      cout << Se;
  }
}
