#include <bits/stdc++.h>
using namespace std;
int a, b, c, d[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c;
  a = a % b;
  d[a]++;
  int t;
  for (int i = 1; i <= 100005; ++i) {
    t = a * 10 / b;
    if (t == c) {
      cout << i;
      exit(0);
    }
    a = ((a * 10) % b);
    d[a]++;
    if (d[a] == 2) {
      cout << "-1";
      exit(0);
    }
  }
}
