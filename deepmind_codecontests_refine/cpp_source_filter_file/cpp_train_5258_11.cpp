#include <bits/stdc++.h>
using namespace std;
int n, t, a, b, c;
char s1[100001], s2[100001];
bool same[100001];
char dif(char d, char e) {
  for (int i = 0; i < 3; i++) {
    char f = 'a' + i;
    if (d != f && e != f) return f;
  }
}
int main() {
  cin >> n >> t;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++)
    if (s1[i] == s2[i]) a++, same[i] = 1;
  if (a + (n - a) / 2 < n - t) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (same[i])
      if (b + c / 2 < n - t)
        b++, cout << s1[i];
      else
        cout << dif(s1[i], s2[i]);
    else if (b + c / 2 < n - t) {
      if (c % 2 == 0)
        if (n - a > 1)
          a++, c++, cout << s2[i];
        else
          cout << dif(s1[i], s2[i]);
      else
        a++, c++, cout << s1[i];
    } else
      cout << dif(s1[i], s2[i]);
  }
  cout << endl;
}
