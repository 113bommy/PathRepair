#include <bits/stdc++.h>
using namespace std;
int N, a, b, c;
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> a >> b >> c;
    if (a <= b && a <= c)
      cout << "1" << endl;
    else if (a < b && a > c)
      cout << a - b + 1 << endl;
    else if (a < c && a > b)
      cout << a - c + 1 << endl;
    else if (b > c)
      cout << a - c + 1 << endl;
    else
      cout << a - b + 1 << endl;
  }
  return 0;
}
