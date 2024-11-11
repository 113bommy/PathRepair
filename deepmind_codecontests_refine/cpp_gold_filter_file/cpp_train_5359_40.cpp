#include <bits/stdc++.h>
using namespace std;
bool happyB[100] = {};
bool happyG[100] = {};
int main() {
  int n, m, b, g;
  cin >> n >> m;
  cin >> b;
  for (int i = 0; i < b; i++) {
    int tmp;
    cin >> tmp;
    happyB[tmp] = true;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int tmp;
    cin >> tmp;
    happyG[tmp] = true;
  }
  for (int it = 0; it < n + m; it++) {
    for (int i = 0; i < n * m; i++) {
      happyB[i % n] |= happyG[i % m];
      happyG[i % m] |= happyB[i % n];
    }
  }
  bool good = true;
  for (int i = 0; i < n; i++) good &= happyB[i];
  for (int i = 0; i < m; i++) good &= happyG[i];
  if (good)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
