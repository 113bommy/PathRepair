#include <bits/stdc++.h>
using namespace std;
int tab[1000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  int ma = 100000000;
  int wy;
  for (int i = 0; i < n; i++) {
    wy = 0;
    for (int j = 0; j < n; j++) {
      wy += (max(i - j, j - i) + j + i) * tab[j];
    }
    if (wy < ma) {
      ma = wy;
    }
  }
  cout << ma;
}
