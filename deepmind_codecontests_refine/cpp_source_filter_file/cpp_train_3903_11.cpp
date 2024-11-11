#include <bits/stdc++.h>
using namespace std;
long long int a, b[1005], c = 0, d = 0, i, j;
void rec(long long int n) {
  if (n == a || n > a) {
    c++;
    b[c] = n;
    return;
  }
  c++;
  b[c] = n;
  rec(n * 10 + 4);
  rec(n * 10 + 7);
}
int main() {
  cin >> a;
  rec(4);
  rec(7);
  sort(b + 1, b + c + 1);
  for (i = 1; i <= c; i++) {
    if (b[i] == a) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
