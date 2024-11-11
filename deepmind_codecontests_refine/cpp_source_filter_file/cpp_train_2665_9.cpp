#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int n, k;
int solve1(int b, int e) {
  if (b == e) return b;
  int mid = (b + e) / 2;
  cout << 1 << " " << mid << " " << mid + 1 << endl;
  string x;
  cin >> x;
  if (x == "NIE") return solve1(b, mid);
  return solve1(mid + 1, e);
}
int main() {
  cin >> n >> k;
  int r1 = solve1(1, n);
  int r2 = -1;
  int r3 = -1;
  if (r1 > 1) r2 = solve1(1, r1 - 1);
  if (r1 < n) r3 = solve1(r1 + 1, n);
  if (r2 == -1) r2 = r3;
  if (r2 != -1 and r3 != -1) {
    cout << 1 << " " << r1 << " " << r2 << endl;
    string s;
    cin >> s;
    if (s == "TAK") {
      cout << 1 << " " << r2 << " " << r1 << endl;
      cin >> s;
      if (s != "TAK") r2 = r3;
    } else {
      assert(true);
    }
  }
  cout << 2 << " " << r1 << " " << r2 << endl;
  return 0;
}
