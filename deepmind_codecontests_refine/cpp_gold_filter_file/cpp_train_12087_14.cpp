#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 100, a, flag = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      flag++;
    }
  }
  if (flag > 0) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
}
