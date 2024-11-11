#include <bits/stdc++.h>
using namespace std;
char s[202020];
long long h, a, r, d;
int main() {
  int n, x;
  cin >> n;
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (s[i] == 'h') h += x;
    if (s[i] == 'a') a += min(h, a + x);
    if (s[i] == 'r') r += min(a, r + x);
    if (s[i] == 'd') d += min(r, d + x);
  }
  cout << d << endl;
}
