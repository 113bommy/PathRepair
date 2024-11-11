#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> v(115);
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    int p = v[i].find('B');
    if (p != string::npos) {
      int t = 0;
      for (int j = p; j < n; j++) {
        if (v[i][j] == 'B')
          t++;
        else
          break;
      }
      cout << i + t / 2 + 1 << " " << p + t / 2 + 1 << '\n';
      break;
    }
  }
  return 0;
}
