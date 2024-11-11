#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  int m, h;
  while (T--) {
    cin >> h >> m;
    int sum = 0;
    if (m < 60 && h < 24 && h > 0) {
      sum += (60 - m);
      h++;
      sum += (24 - h) * 60;
    }
    cout << sum << endl;
  }
  return 0;
}
