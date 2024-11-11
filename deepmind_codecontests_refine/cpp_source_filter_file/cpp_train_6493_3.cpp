#include <bits/stdc++.h>
using namespace std;
int a, b, i, j, c, n, d, k, l, m, p[1000][1000], pas;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) pas = pas + i - (n - i);
  cout << pas + n;
}
