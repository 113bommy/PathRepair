#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0, c = 0, p1 = 0, p2 = 0, h = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < n * 2; i++) {
    if (s[i] == '1' && t[i] != '1') a++;
    if (t[i] == '1' && s[i] != '1') b++;
    if (s[i] == '1' && t[i] == '1') c++;
  }
  int m = min(a, b);
  a -= m;
  b -= m;
  p1 = c % 2;
  h = c % 2;
  p1 += (a + (!h)) / 2;
  p2 += (b + h) / 2;
  if (p1 > p2)
    cout << "First";
  else if (p2 > p1)
    cout << "Second";
  else
    cout << "Draw";
  return 0;
}
