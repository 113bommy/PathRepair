#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, h, w, k, answer = 0;
  cin >> w >> h >> k;
  for (i = 0; i < k; i++) {
    answer += 2 * h + w * 2 - 4;
    h -= 2;
    w -= 2;
  }
  cout << answer;
  return 0;
}
