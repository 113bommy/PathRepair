#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int max_min_street = 0;
  for (int i = 0; i < N; i++) {
    int m = 999999999;
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      m = min(m, a);
    }
    max_min_street = max(max_min_street, m);
  }
  cout << max_min_street << endl;
  return 0;
}
