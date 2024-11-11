#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = N; i > 0; i--) {
    if (M % i == 0) {
      cout << i << endl;
      return 0;
    }
  }
}
