#include <bits/stdc++.h>
using namespace std;
long long modder = 1e+9 + 7;
void solution() {
  int n;
  cin >> n;
  long long out = 1;
  for (int i = n; i >= 2; i--) {
    out *= i;
    out %= modder;
  }
  long long lessener = 1;
  for (int i = 1; i < n; i++) {
    lessener *= 2;
    lessener %= modder;
  }
  out -= lessener;
  out %= modder;
  if (out < 0) {
    out = modder + out;
  }
  cout << out << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long count, counter = 0;
  count = 1;
  while (counter++ < count) {
    solution();
  }
  return 0;
}
