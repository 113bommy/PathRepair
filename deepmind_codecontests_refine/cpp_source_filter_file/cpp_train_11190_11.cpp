#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int w, m;
  cin >> w >> m;
  int g[102] = {};
  for (int i = 0; i <= 100 || m > 0; i++) {
    g[i] = m % w;
    m /= w;
  }
  for (int i = 0; i <= 100; i++) {
    if (g[i] == w || g[i] == w - 1) {
      g[i] = 0;
      g[i + 1]++;
    }
  }
  bool possible = true;
  for (int i = 0; i <= 100 && possible; i++) {
    if (g[i] == 0 || g[i] == 1) continue;
    possible = false;
  }
  if (g[101] > 0) possible = false;
  cout << (possible ? "YES" : "NO") << endl;
  return 0;
}
