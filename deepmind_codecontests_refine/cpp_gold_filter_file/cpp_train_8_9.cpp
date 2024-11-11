#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
int n;
int ans;
string s;
int main() {
  cin >> n >> s;
  for (auto c : s) ans += c == '8';
  cout << min(ans, n / 11) << endl;
}
