#include "bits/stdc++.h"

using namespace std;

int main() {
  int N;
  cin >> N;
  int mi = (int)1e9 + 10, rank = -1;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (b < mi) {
      mi = b;
      rank = a;
    }
  }
  cout << rank + mi << endl;
}
