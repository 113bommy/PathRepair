#include <bits/stdc++.h>
using namespace std;
string s;
int rev(int x) {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    if ((x >> i) & 1) {
      ans = ans | (1 << (7 - i));
    }
  }
  return ans;
}
int sf(int x) { return (((x % 256) + 256) % 256); }
int main() {
  ios_base::sync_with_stdio(0);
  getline(cin, s);
  int prev = 0;
  for (int i = 0; i < s.length(); i++) {
    printf("%d\n", sf(rev(prev) - rev(s[i])));
    prev = s[i];
  }
  return 0;
}
