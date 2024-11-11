#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, act = 0, turn = 0, s = 0;
  int num[2000];
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> num[i + 1];
  }
a:
  for (size_t i = 0; i < n; i++) {
    if (act >= num[i + 1]) {
      act = act + 1;
      num[i + 1] = 99999;
      s = s + 1;
    }
  }
  if (s >= n) {
    cout << turn;
    return 0;
  } else {
    turn = turn + 1;
  }
  for (size_t i = n; i > 0; i--) {
    if (act >= num[i]) {
      act = act + 1;
      num[i + 1] = 99999;
      s = s + 1;
    }
  }
  if (s >= n) {
    cout << turn;
    return 0;
  } else {
    turn = turn + 1;
    goto a;
  }
}
