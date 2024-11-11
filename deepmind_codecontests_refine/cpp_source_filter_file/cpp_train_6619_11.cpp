#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int socks[100001] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int curr = 0;
  int maks = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int sk;
    cin >> sk;
    if (socks[sk] == 0) {
      curr++;
      maks = max(curr, maks);
      socks[sk]++;
    } else {
      curr--;
      socks[sk]++;
    }
  }
  cout << maks << "\n";
  ;
  return 0;
}
