#include <bits/stdc++.h>
using namespace std;
const int OO = 1e8 + 10;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 1;
const double EPS = (1e-9);
int pve[112], nve[112];
int main() {
  string str;
  int x = 1, y = 0, n, sum, idx1 = 0, idx2 = 0;
  char c;
  while (cin >> c && c != '=') {
    if (c == '+')
      x++;
    else if (c == '-')
      y++;
    str.push_back(c);
  }
  sum = x - y;
  cin >> n;
  if (sum < n)
    for (int i = 0; i < x; i++) {
      pve[i] = min(n - 1, n - sum);
      sum += pve[i];
    }
  else
    for (int i = 0; i < y; i++) {
      nve[i] = min(n - 1, n - sum);
      sum -= nve[i];
    }
  if (sum != n) return cout << "Impossible\n", 0;
  cout << "Possible\n" << pve[idx1++] + 1 << ' ';
  for (int i = 1; i < (int)str.size(); i++) {
    if (str[i] == '+' || str[i] == '-')
      cout << str[i] << ' ';
    else if (str[i - 1] == '+')
      cout << pve[idx1++] + 1 << ' ';
    else if (str[i - 1] == '-')
      cout << nve[idx2++] + 1 << ' ';
  }
  cout << "= " << n << '\n';
  return 0;
}
