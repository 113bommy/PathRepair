#include <bits/stdc++.h>
using namespace std;
enum { Right = 0, down, Left, up, rightdown, leftdown, leftup, rightup };
const int p_row[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int p_col[] = {1, 0, -1, 0, 1, -1, -1, 1};
int main() {
  int n, u, d, l, r, ll, rr;
  scanf("%d %d", &n, &u);
  d = 7 - u;
  for (int i = 0; i != n; ++i) {
    scanf("%d %d", &l, &r);
    rr = 7 - r, ll = 7 - l;
    unordered_set<int> s;
    s.insert({ll, rr, l, r, d, u});
    if ((int)(s.size()) != 6) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
