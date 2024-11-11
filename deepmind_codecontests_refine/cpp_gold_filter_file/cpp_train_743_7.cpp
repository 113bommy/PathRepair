#include <bits/stdc++.h>
using namespace std;
int N, K, M, T;
int main() {
  cin >> N >> K >> M >> T;
  int l = N;
  int k = K;
  int a, i;
  while (T > 0) {
    cin >> a >> i;
    if (a == 1) {
      l++;
      if (i <= k) k++;
    } else {
      l = l - i;
      if (i < k) {
        k = k - i;
      } else {
        l = l - (l - i);
      }
    }
    cout << l << " " << k << "\n";
    T--;
  }
}
