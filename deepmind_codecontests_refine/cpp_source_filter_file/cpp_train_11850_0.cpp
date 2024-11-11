#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = M / N; i > 0; i--)
    if (M % N == 0) {
      cout << i << endl;
      break;
    }
}
