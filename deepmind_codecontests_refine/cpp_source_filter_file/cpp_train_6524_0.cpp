#include <bits/stdc++.h>
using namespace std;
long long tests;
long long n, p, x, y;
string s;
void solve() {
  cin >> n >> x >> y >> s;
  for (int i = 1; i < s.size(); i++)
    if (s[i] == '1' && s[i - 1] == '0') p++;
  if (s[s.size() - 1] == '0') p++;
  p--;
  if (p > 0)
    cout << p * min(x, y) + y;
  else
    cout << p;
}
int main() { solve(); }
