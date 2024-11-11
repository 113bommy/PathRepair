#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, flag = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      flag++;
    }
  }
  if (flag == 1) {
    cout << "HARD";
  } else {
    cout << "EASY";
  }
}
