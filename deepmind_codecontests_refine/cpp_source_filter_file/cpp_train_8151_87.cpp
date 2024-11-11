#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int a[8];
void input() {
  for (int i = 0; i < 8; i++) cin >> a[i];
}
void output() {
  cout << min(min(a[1] * a[2] / a[6], a[3] * a[4]), a[5] * a[7]) / a[0];
  exit(0);
}
void solve() {
  input();
  output();
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
