#include <bits/stdc++.h>
using namespace std;
map<int, int> mp1, mp2;
map<pair<int, int>, int> mp3;
int main() {
  int n;
  cin >> n;
  long long l = 0, r = 0, e = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    l += mp1[x];
    r += mp2[y];
    mp1[x]++;
    mp2[y]++;
    e += mp3[make_pair(x, y)];
    mp3[make_pair(x, y)]++;
  }
  cout << (l + r) - e << endl;
  return 0;
}
