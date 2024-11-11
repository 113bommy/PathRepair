#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int n;
  cin >> n;
  int four = 0, seven = 0;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i * 7 + j * 4 == n) {
        seven = i, four = j;
        flag = true;
        break;
      } else if (i * 7 + j * 4 > n)
        break;
    }
    if (flag) break;
  }
  while (four >= 7) {
    four -= 7;
    seven++;
  }
  if (four == 0 && seven == 0) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < four; i++) {
      cout << "4";
    }
    for (int i = 0; i < seven; i++) {
      cout << "7";
    }
  }
}
