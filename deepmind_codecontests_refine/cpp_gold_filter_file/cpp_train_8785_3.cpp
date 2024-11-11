#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, curr = 1;
  cin >> n;
  c = n * n + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      cout << curr << ' ';
      cout << c - curr << ' ';
      curr++;
    }
    cout << endl;
  }
}
