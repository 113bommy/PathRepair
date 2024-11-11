#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i, flag = 0;
  for (i = 0; i < n; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      flag = 1;
    }
  }
  if (flag == 0) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
  return 0;
}
