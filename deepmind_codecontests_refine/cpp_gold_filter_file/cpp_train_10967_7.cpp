#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0, i = 0;
  cin >> n >> k;
  int mas[202];
  for (int i = 1; i <= 2 * n + 1; i++) {
    cin >> mas[i];
  }
  i = 2 * n;
  while (k > 0) {
    if ((mas[i] - 1 > mas[i - 1]) && (mas[i] - 1 > mas[i + 1])) {
      mas[i]--;
      k--;
    }
    i -= 2;
  }
  for (int i = 1; i <= 2 * n + 1; i++) {
    cout << mas[i] << " ";
  }
}
