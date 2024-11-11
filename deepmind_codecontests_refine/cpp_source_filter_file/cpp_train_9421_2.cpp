#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  bool hor[n + 1], ver[n + 1];
  vector<int> sol;
  for (int i = 0; i <= n; i++) {
    hor[i] = false;
    ver[i] = false;
  }
  for (int i = 1; i <= n * n; i++) {
    int x, y;
    cin >> x >> y;
    if (!hor[x] && !ver[y]) {
      hor[i] = true;
      ver[i] = true;
      sol.push_back(i);
    }
  }
  for (int i = 0; i < sol.size(); i++) {
    cout << sol[i] << " ";
  }
  return 0;
}
