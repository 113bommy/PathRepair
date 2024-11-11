#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  int64_t answer = 0;
  for (int64_t i = 0, j = n - 1; i < j && i < k; i++, j--) {
    answer += 2 * (j - i) - 1;
  }
  cout << answer << endl;
}
