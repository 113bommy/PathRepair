#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:33554432")
long long L, R;
int K;
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, k;
  cin >> L >> R >> K;
  if (R - L + 1 < 10) {
    int S = R - L + 1;
    long long ans = 1e18;
    vector<long long> list;
    for (int msk = 1; msk < (1 << S); msk++) {
      long long x = 0;
      int cnt = 0;
      vector<long long> tmp;
      for (i = 0; i < S; i++)
        if (msk & (1 << i)) {
          x ^= L + i;
          cnt++;
          tmp.push_back(L + i);
        }
      if (cnt > K) continue;
      if (ans > x) ans = x, list = tmp;
    }
    cout << ans << "\n" << ((int)(list).size()) << "\n";
    for (int x : list) cout << x << " ";
    cout << "\n";
    return 0;
  }
  if (K == 1) {
    cout << L << "\n" << 1 << "\n" << L << "\n";
    return 0;
  }
  long long a = L & 1 ? L + 1 : L;
  if (K == 2) {
    cout << "1\n2\n" << a << " " << a + 1 << endl;
    return 0;
  }
  if (K >= 4) {
    cout << "0\n4\n"
         << a << " " << a + 1 << " " << a + 2 << " " << a + 3 << "\n";
    return 0;
  }
  long long p = 1, q = 3;
  while (q <= R) {
    if (p >= L) {
      cout << "0\n3\n" << p << " " << q - 1 << " " << q << "\n";
      return 0;
    }
    p = (p << 1) + 1;
    q <<= 1;
  }
  cout << "1\n2\n" << a << " " << a + 1 << endl;
}
