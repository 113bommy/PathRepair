#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
const int eps = 1e-10;
const int base = 1e9;
int A[300] = {0};
void check(char a, long long &sum, long long t) {
  if (A[a] > t)
    sum = 1, t = A[a];
  else if (A[a] == t)
    sum++, t = A[a];
}
int main() {
  long long n, ans = 1, i, sum = 0, t = 0;
  string s;
  cin >> n >> s;
  while (i < n) A[s[i]]++, i++;
  check('A', sum, t);
  check('C', sum, t);
  check('G', sum, t);
  check('T', sum, t);
  for (i = 0; i < n; i++) ans = (ans * 1ll * sum) % 1000000007;
  cout << ans << endl;
  return 0;
}
