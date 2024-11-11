#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int T;
  cin >> T;
  int N, M;
  while (T-- > 0) {
    cin >> N >> M;
    vector<int> a(N);
    int suma = 0;
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
      suma += 2 * a[i];
    }
    if (M < N || N < 3) {
      cout << -1 << endl;
    } else {
      cout << suma << endl;
      for (int i = 1; i <= N; ++i) {
        int nexti = i + 1;
        if (nexti == N + 1) nexti = 1;
        cout << i << " " << nexti << endl;
      }
    }
  }
  return 0;
}
