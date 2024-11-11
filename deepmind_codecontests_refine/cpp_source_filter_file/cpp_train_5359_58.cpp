#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int X[6] = {0, 0, 0, -1, 0, 1};
int Y[6] = {0, 0, -1, 0, 1, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
int main() {
  int n, m, b, g;
  cin >> n >> m >> b;
  unordered_map<int, bool> hb, hg;
  unordered_map<int, bool>::iterator it;
  int hbb = 0, hgg = 0;
  for (int i = 0; i < b; i++) {
    int a;
    cin >> a;
    hb[a] = 1;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int a;
    cin >> a;
    hg[a] = 1;
  }
  for (int i = 0; i < 3000; i++) {
    int a = i % n, b = i % m;
    if (hb[a] || hg[b]) {
      hb[a] = hg[b] = 1;
    }
  }
  for (it = hb.begin(); it != hb.end(); it++) {
    hbb += (*it).second;
  }
  for (it = hg.begin(); it != hg.end(); it++) {
    hgg += (*it).second;
  }
  if (hbb == n && hgg == m)
    cout << "Yes\n";
  else
    cout << "NO\n";
}
