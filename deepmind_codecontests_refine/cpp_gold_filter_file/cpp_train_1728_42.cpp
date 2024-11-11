#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10, mod = 1e9 + 7, oo = INT_MAX;
long long n;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cin >> n;
  long long cost = 0;
  for (long long i = 1; i < ((n) / 2) + n % 2; i++) {
    cost += 1;
  }
  cout << cost << "\n";
  return 0;
}
