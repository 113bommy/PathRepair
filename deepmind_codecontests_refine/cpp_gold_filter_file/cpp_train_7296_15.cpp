#include <bits/stdc++.h>
using namespace std;
bool cor[100100];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> m >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cout << "1\n";
    cout.flush();
    cin >> x;
    if (x == 0) {
      return 0;
    }
    if (x == 1) {
      cor[i] = 1;
    }
  }
  int l = 1, h = m;
  int i = 0;
  while (l <= h) {
    int md = (l + h) / 2;
    cout << md << "\n";
    cout.flush();
    cin >> x;
    if (x == 0) return 0;
    if (!cor[i]) x *= -1;
    i++;
    i %= n;
    if (x == 1)
      l = md + 1;
    else
      h = md - 1;
  }
  return 0;
}
