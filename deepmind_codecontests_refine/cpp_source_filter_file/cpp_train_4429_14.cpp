#include <bits/stdc++.h>
using namespace std;
int n, c;
int p[51], t[51];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
  int a = 0, b = 0;
  int cur_t = 0;
  for (int i = 1; i <= n; i++) {
    cur_t += t[i];
    a += max(0, p[i] - c * cur_t);
  }
  cur_t = 0;
  for (int i = n; i >= 1; i--) {
    cur_t += t[i];
    b += max(0, p[i] - c * cur_t);
  }
  if (a == b)
    cout << "Tie";
  else if (a > b)
    cout << "Limak";
  else
    cout << "Radewhoosh";
}
