#include <bits/stdc++.h>
using namespace std;
int num[1000002];
int main() {
  int N, M, K;
  while (cin >> N >> M >> K) {
    memset((num), (0x7f), sizeof(num));
    for (int j = 0; j < (int)(N); ++j) {
      int r, c;
      cin >> r >> c;
      --r;
      num[r] = min(num[r], c);
    }
    int res = 0;
    for (int k = 0; k < (int)(M); ++k) res += num[k];
    cout << min(res, K) << endl;
  }
}
