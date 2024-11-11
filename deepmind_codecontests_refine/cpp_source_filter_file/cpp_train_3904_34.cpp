#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << "NO";
    return 0;
  }
  int ms[101][2];
  for (int i = 0; i < k; i++) cin >> ms[i][0] >> ms[i][1];
  bool trg = false;
  for (int i = 0; i < k; i++) {
    if (ms[i][0] - 4 <= 0 || ms[i][0] + 4 >= n || ms[i][1] + 4 >= m ||
        ms[i][1] - 4 <= 0) {
      trg = true;
      break;
    }
  }
  if (trg == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
