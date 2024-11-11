#include <bits/stdc++.h>
using namespace std;
bool dfs(unsigned long long a, unsigned long long b) {
  if (a > b) {
    swap(a, b);
  }
  if (a == 0) {
    return false;
  }
  if (dfs(a, b % a)) {
    if (((b / a) % (a + 1)) % 2 == 0) {
      return true;
    }
    return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unsigned long long a, b;
    cin >> a >> b;
    if (dfs(a, b)) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }
  return 0;
}
