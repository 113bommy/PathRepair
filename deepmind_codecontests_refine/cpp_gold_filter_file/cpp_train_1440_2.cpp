#include <bits/stdc++.h>
using namespace std;

int N, X, M = INT_MAX;

int main() {
  cin >> N >> X;
  for(int i = 0; i < N; ++i) {
    int m; cin >> m; X -= m; if(m < M) M = m;
  }
  cout << N + X / M << endl;
  return 0;
}
