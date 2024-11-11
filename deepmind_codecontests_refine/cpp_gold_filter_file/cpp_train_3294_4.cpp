#include <bits/stdc++.h>
using namespace std;
int N;
int T;
int K;
int a[100005];
int main() {
  int i, j, k;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof(a));
    cin >> N >> K;
    int s = 0;
    if (K == 1) {
      int b;
      cin >> b;
      cout << max(b, N - b + 1) << endl;
      continue;
    }
    for (i = 1; i <= K; i++) {
      cin >> a[i];
    }
    for (i = 2; i <= K; i++) {
      s = max(s, a[i] - a[i - 1]);
    }
    cout << max(s / 2 + 1, max(a[1], N - a[K] + 1)) << endl;
  }
}
