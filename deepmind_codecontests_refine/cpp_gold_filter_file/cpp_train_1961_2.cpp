#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin >> N;
  N++;
  int count = 0;
  while (N >= 10) {
    N /= 10;
    count++;
  }
  cout << N - 1 + 9 * count << '\n';
  return 0;
}
