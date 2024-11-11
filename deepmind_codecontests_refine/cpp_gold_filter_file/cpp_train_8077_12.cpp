#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const long long INF = 2e11 + 29;
int main() {
  int a, b;
  cin >> a >> b;
  int konf = 0;
  while (a >= 0 && b >= 0) {
    if (konf % 2 == 0) {
      a -= konf + 1;
    } else {
      b -= konf + 1;
    }
    konf++;
  }
  cout << (konf % 2 ? "Vladik" : "Valera");
}
