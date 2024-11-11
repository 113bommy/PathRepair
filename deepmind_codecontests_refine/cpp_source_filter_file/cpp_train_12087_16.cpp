#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0, i, l;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> l;
    if (l == 1) {
      cnt += 1;
    }
  }
  if (l > 0) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
}
