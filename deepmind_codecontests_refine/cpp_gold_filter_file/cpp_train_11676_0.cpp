#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int F(int a) {
  ++a;
  while (a % 10 == 0 && a) {
    a /= 10;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<int> second{n};
  while (F(n)) {
    n = F(n);
    if (second.count(n)) break;
    second.insert(n);
  }
  cout << second.size();
  return 0;
}
