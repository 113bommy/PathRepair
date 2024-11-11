#include <bits/stdc++.h>
using namespace std;
void _main(int tc) {
  int n, x, y;
  cin >> n >> x >> y;
  n--;
  int dist = y - x;
  int auxn = 1;
  while (true) {
    if (dist % auxn == 0 && dist / auxn <= n) {
      break;
    }
    auxn++;
  }
  int missing = n - dist / auxn;
  ;
  ;
  ;
  ;
  int smallest = x;
  while (missing && smallest > 0) {
    smallest -= auxn;
    missing--;
  }
  if (smallest <= 0) {
    smallest += auxn;
    missing++;
  }
  long long int greatest = y;
  while (missing) {
    greatest += auxn;
    missing--;
  };
  ;
  for (int i = smallest; (auxn < 0) ? i > greatest + 1 : i < greatest + 1;
       i += auxn) {
    cout << i << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 0; ((0 < tc ? 1 : -1) < 0) ? i > tc : i < tc;
       i += (0 < tc ? 1 : -1))
    _main(i + 1);
}
