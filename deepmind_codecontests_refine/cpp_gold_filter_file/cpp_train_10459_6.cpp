#include <bits/stdc++.h>
using namespace std;
const int NMAX = 10000;
const int INF = 1 << 31;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int a, b;
int main() {
  cin >> a >> b;
  if (a < b)
    cout << "0";
  else if (a == b)
    cout << "infinity";
  else {
    a -= b;
    int first = 0;
    for (int i = 1; i <= sqrt(a); i++) {
      if (a % i == 0) {
        if (i > b) first++;
        if (i != (a / i) && (a / i) > b) first++;
      }
    }
    cout << first;
  }
  return 0;
}
