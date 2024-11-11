#include <bits/stdc++.h>
using namespace std;
int ocur[101] = {0};
int main() {
  int n;
  int r, aux;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r;
    for (int j = 0; j < r; j++) {
      cin >> aux;
      ocur[aux]++;
      if (i == n - 1) {
        if (ocur[aux] == n) cout << aux << " ";
      }
    }
  }
  return 0;
}
