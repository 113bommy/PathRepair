#include <bits/stdc++.h>
using namespace std;
char judge(long long n, long long k, long long pos) {
  pos = n - pos + 1;
  char ans = 0;
  if (k <= 1) {
    if (k == 0)
      ans = '.';
    else if (pos != 1)
      ans = '.';
    else
      ans = 'X';
  } else if ((n & 1) && n / 2 >= k) {
    if (pos <= 2)
      ans = 'X';
    else if (pos > (k - 1) * 2)
      ans = '.';
    else if (pos & 1)
      ans = '.';
    else
      ans = 'X';
  } else {
    if (n / 2 >= k) {
      if (pos >= 2 * k)
        ans = '.';
      else if (pos & 1)
        ans = 'X';
      else
        ans = '.';
    } else {
      int rem = k - (n + 1) / 2;
      if (pos <= rem * 2 + 1)
        ans = 'X';
      else if ((pos & 1) ^ (n & 1))
        ans = 'X';
      else
        ans = '.';
    }
  }
  return ans;
}
int main() {
  long long n, k;
  int p;
  while (cin >> n >> k >> p) {
    string s;
    for (int i = 0, _n(p); i < _n; ++i) {
      long long pos;
      cin >> pos;
      s += (judge(n, k, pos));
    }
    cout << s << endl;
  }
  return 0;
}
