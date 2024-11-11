#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c, aa, aaa, s = 0, n;
  cin >> n >> a;
  c = 7 - a;
  for (int i = 0; i < n; i++) {
    cin >> aa >> aaa;
    if (aa == a || aa == c || aaa == a || aaa == c) s++;
  }
  if (s > 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
