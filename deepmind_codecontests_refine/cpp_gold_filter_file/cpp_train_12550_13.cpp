#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, a, b;
  cin >> n >> c;
  cin >> a;
  int words = 1;
  for (int i = 1; i < n; i++) {
    cin >> b;
    if (b - a > c)
      words = 1;
    else
      words++;
    a = b;
  }
  cout << words << endl;
}
