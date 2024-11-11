#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int za = 0, zb = 0;
  for (int i = 0; i < a.size(); i++) za += (a[i] == '1');
  for (int i = 0; i < b.size(); i++) zb += (b[i] == '1');
  za + za % 2 > zb ? printf("YES\n") : printf("NO\n");
}
