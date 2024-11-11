#include <bits/stdc++.h>
using namespace std;
int n, sayac;
string a, b, q;
map<string, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    q = a + b;
    if (mp[q] == 0) {
      sayac++;
    }
    mp[q]++;
  }
  printf("%d", sayac);
  return 0;
}
