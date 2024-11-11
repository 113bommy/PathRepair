#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, sum = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      int tmp;
      cin >> tmp;
      if (i == j or (i + j) == (N + 1) or i == (N / 2 + 1) or j == (N / 2 + 1))
        sum += tmp;
    }
  }
  cout << sum << endl;
}
