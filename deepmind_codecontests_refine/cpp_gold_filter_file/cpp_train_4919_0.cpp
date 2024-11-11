#include <bits/stdc++.h>
using namespace std;
void solve(int t = 0) {
  int n, s;
  cin >> n >> s;
  if (n == 1 && s > 1) {
    cout << "YES"
         << "\n"
         << s << "\n"
         << s - 1;
    return;
  }
  if (s >= 2 * n) {
    cout << "YES";
    cout << "\n";
    for (int i = 0; i < n - 1; i++) {
      cout << 2;
      cout << " ";
    }
    cout << (s - 2 * (n - 1));
    cout << "\n";
    cout << 1;
    return;
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T = 1;
  for (int t = 0; t < T; t++) solve(t);
}
