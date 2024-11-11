#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  long long n, k, q, odds, evens;
  cin >> n >> k >> q;
  if (n % 2 == 0) {
    odds = n, evens = 0;
    long long energy = (n >> 1);
    if (k <= energy)
      odds = k * 2 - 1;
    else
      evens = (k - energy) * 2;
  } else {
    odds = 1, evens = n - 1;
    long long energy = (n >> 1) + 1;
    if (k <= energy)
      evens = (k - 1) * 2;
    else
      odds = (k - energy) * 2 + 1;
  }
  while (q--) {
    int x;
    cin >> x;
    if (!k) {
      cout << ".";
      continue;
    }
    x = n - x + 1;
    if ((x & 1) && odds >= x)
      cout << 'X';
    else if (!(x & 1) && (evens >= x))
      cout << 'X';
    else
      cout << '.';
  }
  return 0;
}
