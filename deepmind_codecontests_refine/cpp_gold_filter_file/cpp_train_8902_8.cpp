#include <bits/stdc++.h>
using namespace std;
int a[100005], v[100005];
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    if (s[i] == '<') a[i] = -a[i];
  int nw = 0;
  while (true) {
    v[nw] = 1;
    nw += a[nw];
    if (nw < 0 || nw >= n) {
      puts("FINITE");
      return 0;
    }
    if (v[nw]) break;
  }
  puts("INFINITE");
  return 0;
}
