#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1 << 25;
map<int, int> btl;
int a[100], b[100];
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ++btl[b[i]];
  }
  for (int i = 0; i < n; i++) {
    --btl[b[i]];
    if (!btl[a[i]]) ans++;
    ++btl[b[i]];
  }
  cout << ans << endl;
  return 0;
}
