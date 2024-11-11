#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[200001], t1[200001];
  long long n, x, y, t, con = 0;
  cin >> n >> x >> y;
  getchar();
  gets(s);
  t = n - x;
  for (long long i = t; s[i] != '\0'; i++) {
    if (i == n - 1 - y && s[i] != '1') con++;
    if (i != n - 1 - y && s[i] != '0') con++;
  }
  cout << con << endl;
  return 0;
}
