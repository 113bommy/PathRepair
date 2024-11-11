#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = M / N; i >= 1; i--) {
    if (M % i == 0) {
      cout << i << endl;
      break;
    }
  }
}