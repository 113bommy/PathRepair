#include <bits/stdc++.h>
using namespace std;
const int DEBUG = 0;
mt19937 gen(
    (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
#pragma comment(linker, "/STACK:67108864")
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> b(h, vector<int>(w));
  vector<int> p1(w), r1(h), p2(w), r2(h);
  int s1 = 0, s2 = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      s1 += a[i][j];
      p1[j] += a[i][j];
      r1[i] += a[i][j];
    }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> b[i][j];
      s2 += b[i][j];
      p2[j] += b[i][j];
      r2[i] += b[i][j];
    }
  if (s1 % 2 != s2 % 2) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < h; i++)
    if (r1[i] % 2 != r2[i] % 2) {
      cout << "No";
      return 0;
    }
  for (int i = 0; i < w; i++)
    if (p1[i] % 2 != p2[i] % 2) {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}
