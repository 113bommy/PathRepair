#include <bits/stdc++.h>
using namespace std;
string a;
int ans = 0;
void input();
void solve();
int main() {
  input();
  solve();
  return 0;
}
void input() { cin >> a; }
void solve() {
  int n = a.size();
  int i, j;
  int p;
  int br = 0;
  for (i = n - 1; i >= 0; i--) {
    if (a[i] == '0') {
      ans = (ans * 2) % 1000000007;
    } else {
      ans = (ans * 2) % 1000000007;
      p = 1;
      for (j = 0; j < 2 * br; j++) {
        p = (p * 2) % 1000000007;
      }
      ans = (ans + p) % 1000000007;
    }
    br++;
  }
  printf("%d\n", ans);
}
