#include <bits/stdc++.h>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
int t, n;
char c[200005];
void solve() {
  int start, End, sol = 0;
  for (start = 1; start < n && c[start] == c[n]; start++)
    ;
  if (start == n) {
    cout << (n + 2) / 3 << "\n";
    return;
  }
  for (End = n; End >= 1 && c[End] == c[1]; End--)
    ;
  sol += ((start - 1) + (n - End)) / 3;
  char val = c[start];
  int cnt = 0;
  for (int i = start; i <= End; i++) {
    if (c[i] == val) {
      cnt++;
    } else {
      val = c[i];
      sol += cnt / 3;
      cnt = 1;
    }
  }
  sol += cnt / 3;
  cout << sol << "\n";
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> c + 1;
    solve();
  }
}
