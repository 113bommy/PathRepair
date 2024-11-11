#include <bits/stdc++.h>
using namespace std;
int main() {
  int32_t n, k;
  cin >> n >> k;
  int32_t answer = 0;
  for (int32_t i = 0, j = n - 1; i < j && i < k; i++, j--) {
    answer += 2 * (j - i) - 1;
  }
  cout << answer << endl;
}
