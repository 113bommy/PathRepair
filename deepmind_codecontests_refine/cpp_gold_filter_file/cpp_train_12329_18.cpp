#include <bits/stdc++.h>
using namespace std;
int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int n;
  string s;
  scanf("%d", &n);
  cin >> s;
  long long num = 0;
  for (int i = (0); i < (n); i++) {
    if (s[i] == 'B') num |= (1LL << i);
  }
  cout << (num), cout << (endl);
  return 0;
}
