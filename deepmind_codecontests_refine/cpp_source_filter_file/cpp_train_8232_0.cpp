#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, INF = 1e9 + 7;
int n, h, a, b, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> h >> a >> b >> k;
  for (int i = 0; i < k; ++i) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    if (ta == tb) {
      cout << abs(fa - fb) << '\n';
    } else {
      if (a <= fa && fa <= b || a <= fb && fb <= b)
        cout << abs(fa - fb) + abs(ta - tb) << '\n';
      else {
        if (abs(fa - a) < abs(fa - b))
          cout << abs(fa - a) + abs(fb - b) + abs(ta - tb) << '\n';
        else
          cout << abs(fa - b) + abs(fb - b) + abs(ta - tb) << '\n';
      }
    }
  }
  return 0;
}
