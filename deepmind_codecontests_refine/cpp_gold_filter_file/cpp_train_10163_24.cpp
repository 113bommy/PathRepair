#include <bits/stdc++.h>
using namespace std;
int coin[] = {1, 2};
int way[200007];
int main() {
  way[0] = 1;
  for (int i = 0; i <= 1; i++) {
    for (int j = coin[i]; j <= 200005; j++) {
      way[j] += way[j - coin[i]];
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= 200005; i++) {
    if (way[i] == n) {
      cout << i << ' ' << 2 << endl;
      cout << 1 << ' ' << 2 << endl;
      return 0;
    }
  }
}
