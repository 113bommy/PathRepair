#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9;
bool check(int n, string s) {
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') return false;
  cout << 2 << ' ' << n << ' ' << 1 << ' ' << n << endl;
  return true;
}
void sol(int n, string s) {
  for (int i = 1; i <= n; i++)
    if (s[i] == '0') {
      if (i - 1 >= n / 2)
        cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
      else
        cout << i << " " << n << " " << i + 1 << " " << n << endl;
      return;
    }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    if (!check(n, s)) sol(n, s);
  }
  return 0;
}
