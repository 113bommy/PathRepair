#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
const int MOD = 1000000007;
long long fun(long long a, long long b) {
  if (a > b) return a;
  return b;
}
void swp(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  char ch;
  long long x, y;
  cin >> ch >> x >> y;
  if (x > y) swp(&x, &y);
  long long mx = x, my = y;
  n--;
  while (n--) {
    cin >> ch >> x >> y;
    if (x > y) swp(&x, &y);
    if (ch == '+') {
      mx = fun(mx, x);
      my = fun(my, y);
    } else {
      if ((x >= mx && y >= my) || (x >= my && y >= mx))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
