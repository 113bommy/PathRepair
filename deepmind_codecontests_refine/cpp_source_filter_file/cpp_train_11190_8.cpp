#include <bits/stdc++.h>
#pragma comment(linker, ”/ STACK : 36777216“)
int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
int main() {
  int w, m;
  cin >> w >> m;
  vector<int> W;
  while (m) {
    W.push_back(m % w);
    m /= w;
  }
  W.push_back(0);
  W.push_back(0);
  for (int _n((W.size() - 1) - 1), i(0); i <= _n; ++i) {
    if (W[i] && W[i] != 1 && w - W[i] && w - W[i] != 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (w - W[i] == 0 || w - W[i] == -1) W[i + 1]++;
  }
  cout << "YES" << endl;
  return 0;
}
