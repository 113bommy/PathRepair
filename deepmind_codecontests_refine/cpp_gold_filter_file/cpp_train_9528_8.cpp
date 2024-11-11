#include <bits/stdc++.h>
using namespace std;
long long N;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  long long a = N + 4;
  a = (a * (a - 1) * (a - 2) * (a - 3) * (a - 4)) / (5 * 4 * 3 * 2 * 1);
  long long b = N + 2;
  b = (b * (b - 1) * (b - 2)) / 6;
  cout << a * b << '\n';
  ;
}
