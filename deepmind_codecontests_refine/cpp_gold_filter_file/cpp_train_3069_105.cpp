#include <bits/stdc++.h>
using namespace std;
char a;
int ans, cnt;
int main() {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      cin >> a;
      if (a == 'Q') ans += 9;
      if (a == 'R') ans += 5;
      if (a == 'B') ans += 3;
      if (a == 'N') ans += 3;
      if (a == 'P') ans += 1;
      if (a == 'q') cnt += 9;
      if (a == 'r') cnt += 5;
      if (a == 'b') cnt += 3;
      if (a == 'n') cnt += 3;
      if (a == 'p') cnt += 1;
    }
  }
  if (ans > cnt) {
    cout << "White";
  } else if (ans < cnt) {
    cout << "Black";
  } else {
    cout << "Draw";
  }
}
