#include <bits/stdc++.h>
using namespace std;
string s;
long n, a, b, c, i, j, k;
void f(string S, long now) {
  string s7(S, 0, now);
  s.erase(0, now);
  cout << s7 << endl;
}
int main() {
  cin >> n >> a >> b;
  cin >> s;
  k = s.size();
  j = k / n;
  if (j >= b || j <= a) {
    cout << "No solution" << endl;
    return 0;
  }
  if (b == j && k % n != 0) {
    cout << "No solution" << endl;
    return 0;
  }
  for (i = 1; i <= k - (j * n); i++) f(s, j + 1);
  while (s.size() > 0) f(s, j);
}
