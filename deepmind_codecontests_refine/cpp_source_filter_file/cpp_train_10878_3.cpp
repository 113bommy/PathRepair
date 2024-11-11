#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char ch;
  int x;
  int max = 0;
  int tmp = 0;
  int WhoIsThere[1000000] = {0};
  for (int i = 0; i < n; i++) {
    cin >> ch >> x;
    if (ch == '+') {
      if (WhoIsThere[x] == 0) {
        WhoIsThere[x]++;
        if (max < tmp + 1) {
          max = tmp + 1;
        }
        tmp += 1;
      }
    }
    if (ch == '-') {
      if (WhoIsThere[x] == 0) {
        max = max + 1;
      }
      if (WhoIsThere[x] == 1) {
        tmp -= 1;
        WhoIsThere[x] = 0;
      }
    }
  }
  cout << max;
  return 0;
}
