#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, k, area, guild, result = 0;
  cin >> w >> h >> k;
  result = ((w * 2 + h * 2) - 4);
  if (k > 0) {
    for (int i = 1; i < k; i++) {
      result += (((w - 4) * 2 + (h - 4) * 2) - 4);
    }
  }
  cout << result << endl;
}
