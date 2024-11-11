#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int sum = 0;
  for (int i = e; i != f; ++i)
    if (i == (((i % a) % b) % c) % d) sum++;
  cout << sum;
}
