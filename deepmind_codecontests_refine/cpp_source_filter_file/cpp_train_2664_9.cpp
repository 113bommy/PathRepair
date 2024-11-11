#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
int n, f;
map<int, char> mp;
int main() {
  scanf("%d", &n);
  string s = "ROYGBIV", ss = "GBIVYG";
  for (int i = 0; i < n / 7; ++i) cout << s;
  for (int i = 0; i < n % 7; ++i) printf("%c", ss[i]);
  return 0;
}
