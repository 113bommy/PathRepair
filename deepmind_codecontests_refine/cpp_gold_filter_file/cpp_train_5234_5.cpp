#include <bits/stdc++.h>
using namespace std;
void solve() {
  string n;
  int s;
  cin >> n >> s;
  int sum = 0;
  for (int i = 0; i < n.length(); i++) {
    sum += n[i] - 48;
  }
  if (sum <= s) {
    cout << 0 << endl;
    return;
  }
  int count = 1;
  int pos = 0;
  for (int i = 0; i < n.length(); i++) {
    pos = i;
    if (count + n[i] - 48 > s) {
      break;
    }
    count += n[i] - 48;
  }
  long long int ans = 0;
  for (int i = pos; i < n.length(); i++) {
    ans = ans * 10 + (57 - n[i]);
  }
  ans++;
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
