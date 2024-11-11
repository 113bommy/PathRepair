#include <bits/stdc++.h>
using namespace std;
int pr[1000002] = {0};
void Seive() {
  pr[1] = 1;
  for (long i = 2; i <= 1000; i++) {
    if (pr[i] == 0) {
      for (long j = 2 * i; j < 1000001; j += i) pr[j] = i;
    }
  }
  for (long i = 2; i < 1000001; i++) {
    if (pr[i] == 0) {
      pr[i] = i;
    }
  }
}
int main(int argc, char const *argv[]) {
  int n, m, j, sum = 0, x;
  j = 1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (x > j) {
      sum = sum + abs(j - x) % n;
    } else if (j > x)
      sum = sum + n - j + x;
    j = x;
  }
  std::cout << sum << endl;
  return 0;
}
