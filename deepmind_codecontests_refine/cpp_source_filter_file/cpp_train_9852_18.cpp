#include <bits/stdc++.h>
using namespace std;
const int INF = 2000;
int fro[INF], beh[INF], n, m, c, cnt = 0, num;
int main() {
  cin >> n >> m >> c;
  fill(fro, fro + n + 1, INF);
  fill(beh, beh + n + 1, 0);
  while (cnt < n) {
    cin >> num;
    if (num * 2 < c) {
      int ind = upper_bound(fro, fro + n + 1, num) - fro;
      cout << ind + 1 << endl;
      cout << flush;
      if (fro[ind] == INF) {
        cnt++;
      }
      fro[ind] = num;
    } else {
      int ind = upper_bound(beh, beh + n + 1, num, greater<int>()) - beh;
      cout << n - ind << endl;
      cout << flush;
      if (beh[ind] == 0) {
        cnt++;
      }
      beh[ind] = num;
    }
  }
}
