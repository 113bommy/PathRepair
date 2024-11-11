#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void debug() {
  cout << "Shit Life"
       << "\n";
}
void timeT() { cerr << "time taken " << (float)clock() / 1e8 << " secs\n"; }
void solve() {
  int n, b, d;
  cin >> n >> b >> d;
  int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > b)
      continue;
    else {
      sum += a;
      if (sum > d) {
        count++;
        sum = 0;
      }
    }
  }
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  while (test--) {
    solve();
  }
}
