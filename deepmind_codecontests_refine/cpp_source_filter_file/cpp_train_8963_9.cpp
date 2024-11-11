#include <bits/stdc++.h>
using namespace std;
vector<int> v1(200001, 0), v2(200001, 0);
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 0, ct1 = 1, ct2 = 1, p1 = 0, p2 = 0;
  cin >> t;
  while (t--) {
    char c;
    int n = 0;
    cin >> c >> n;
    if (c == 'L')
      v1[n] = ct1, p1 = ct1, ct1++;
    else if (c == 'R')
      v2[n] = ct2, p2 = ct2, ct2++;
    else if (v1[n] != 0)
      cout << min(abs(p1 - v1[n]), abs(p2 + v1[n])) << "\n";
    else
      cout << min(abs(p2 - v2[n]), abs(p1 + v1[n])) << "\n";
  }
}
