#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1000005;
int pw[MAXSIZE] = {0};
int main() {
  ios ::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    pw[t]++;
  }
  int carry = 0;
  int ans = 0;
  for (int i = 0; i < MAXSIZE - 2; i++) {
    pw[i] += carry;
    carry = pw[i] / 2;
    pw[i] -= 2 * carry;
    if (pw[i]) ans++;
  }
  cout << ans << "\n";
}
