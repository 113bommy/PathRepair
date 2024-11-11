#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      h++;
    }
  }
  if (h >= 1) {
    cout << "HARD" << endl;
  } else {
    cout << "EASY" << endl;
  }
}
