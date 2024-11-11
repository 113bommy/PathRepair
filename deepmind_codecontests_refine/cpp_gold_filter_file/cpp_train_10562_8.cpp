#include <bits/stdc++.h>
using namespace std;
int main() {
  set<char> se;
  string a, b;
  int n, m;
  scanf("%d%d", &n, &m);
  cin >> a >> b;
  string c = "";
  c += a[0];
  c += b[0];
  c += a[n - 1];
  c += b[m - 1];
  if (c == ">^<v" || c == "<v>^")
    printf("YES");
  else
    printf("NO");
  return 0;
}
