#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int Count[N];
int main() {
  int n, d;
  long long sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d);
    Count[d]++;
  }
  for (int i = 0; i < N; i++) {
    if (Count[i] % 2 == 1) {
      sum++;
    }
    Count[i + 1] += Count[i] / 2;
  }
  cout << sum << "\n";
  return 0;
}
