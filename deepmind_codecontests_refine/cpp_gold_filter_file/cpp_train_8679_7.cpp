#include <bits/stdc++.h>
using namespace std;
bool num[3010];
int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    memset(num, false, sizeof(num));
    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      num[temp] = true;
    }
    for (int i = 1; i <= 3001; i++)
      if (!num[i]) {
        cout << i << endl;
        break;
      }
  }
  return 0;
}
