#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, level;
  cin >> n;
  long long cur = 2;
  for (level = 1; level < n + 1; level++) {
    long long y = level * (level + 1) * (level + 1) - (cur / level);
    cout << y << "\n";
    cur = level * (level + 1);
  }
  return 0;
}
