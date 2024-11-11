#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b, c, d, e, f;
  cin >> n;
  cin >> c >> d;
  cin >> a >> b;
  cin >> e >> f;
  int book1 = 0, book2 = 0;
  if (a < c && b < d) {
    book1 = 1;
  } else if (a < c && b > d) {
    book1 = 2;
  } else if (a > c && b < d) {
    book1 = 3;
  } else if (a > c && b > d) {
    book1 = 4;
  }
  if (e < c && f < d) {
    book2 = 1;
  } else if (e < c && f > d) {
    book2 = 2;
  } else if (e > c && f < d) {
    book2 = 3;
  } else if (e > c && f > d) {
    book2 = 4;
  }
  if (book1 == book2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
