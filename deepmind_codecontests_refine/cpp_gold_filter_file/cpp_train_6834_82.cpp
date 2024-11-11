#include <bits/stdc++.h>
using namespace std;
void g_o_a_l() {
  long long k;
  string s = "";
  cin >> k;
  if (k > 36) {
    cout << -1;
    return;
  }
  if (k & 1) {
    for (int i = 0; i < k / 2; i++) s += '8';
    s += '4';
  } else
    for (int i = 0; i < k / 2; i++) s += '8';
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    g_o_a_l();
  }
  return 0;
}
