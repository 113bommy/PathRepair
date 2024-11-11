#include <bits/stdc++.h>
using namespace std;
int gcd(int p, int q) { return q == 0 ? p : gcd(q, p % q); }
char s[100100];
long long res[2][2];
int main() {
  cin >> s;
  int len = strlen(s);
  memset(res, 0, sizeof(res));
  int a = 0, b = 0;
  for (int i = 0; i < len; i++) {
    int temp = i & 1;
    res[s[i] - 'a'][temp]++;
    a += res[s[i] - 'a'][1 - temp];
    b += res[s[i] - 'a'][temp];
  }
  cout << a << " " << b << endl;
  return 0;
}
