#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int s, f;
  cin >> s >> f;
  if (s > f) {
    swap(s, f);
  }
  int c, b;
  for (int i = s; i < f; i++) {
    c += a[i];
  }
  for (int i = 1; i < s; i++) {
    b += a[i];
  }
  for (int i = f; i <= n; i++) {
    b += a[i];
  }
  cout << min(c, b);
  return 0;
}
