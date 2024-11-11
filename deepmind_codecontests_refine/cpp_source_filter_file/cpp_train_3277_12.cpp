#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  int m, ind[100002];
  cin >> m;
  while (m--) {
    int a;
    cin >> a;
    ind[a - 1]++;
  }
  int temp = 0;
  for (int i = 0; i < s.size() / 2; ++i) {
    temp += ind[i];
    if (temp & 1) swap(s[i], s[s.size() - i - 1]);
  }
  cout << endl << s;
  return 0;
}
