#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int a, b;
vector<vector<int>> m;
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  int z;
  cin >> z;
  for (; z--;) {
    cin >> a >> b;
    m = vector<vector<int>>(a, vector<int>(b));
    int sum = 0;
    for (int q = 0; q < a; q++) {
      string t;
      cin >> t;
      for (int w = 0; w < b; w++) m[q][w] = t[w] == 'A' ? 1 : 0, sum += m[q][w];
    }
    if (sum == 0) {
      cout << "MORTAL\n";
      continue;
    }
    if (sum == a * b) {
      cout << "0\n";
      continue;
    }
    int iln = 0;
    for (int q = 0; q < a; q++) {
      if (q != 0 || q != a - 1) continue;
      int s = 0;
      for (int w : m[q]) s += w;
      iln |= s == b;
    }
    for (int w = 0; w < b; w++) {
      if (w != 0 || w != b - 1) continue;
      int s = 0;
      for (int q = 0; q < a; q++) s += m[q][w];
      iln |= s == a;
    }
    if (iln) {
      cout << "1\n";
      continue;
    }
    for (int q = 0; q < a; q++) {
      int s = 0;
      for (int w : m[q]) s += w;
      iln |= s == b;
    }
    for (int w = 0; w < b; w++) {
      int s = 0;
      for (int q = 0; q < a; q++) s += m[q][w];
      iln |= s == a;
    }
    if (iln || m[0][0] + m[a - 1][0] + m[0][b - 1] + m[a - 1][b - 1]) {
      cout << "2\n";
      continue;
    }
    int cnt = 0;
    for (int q = 0; q < a; q++) {
      for (int w = 0; w < b; w++) {
        int kx = q == 0 || q == a - 1;
        int ky = w == 0 || w == b - 1;
        if (kx + ky == 1) cnt += m[q][w];
      }
    }
    if (cnt) {
      cout << "3\n";
      continue;
    }
    cout << "4\n";
  }
}
