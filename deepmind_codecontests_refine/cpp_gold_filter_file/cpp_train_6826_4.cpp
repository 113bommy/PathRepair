#include <bits/stdc++.h>
using namespace std;
const int MAXN = 64 + 10;
int n, m;
int main() {
  cin >> n;
  string ans;
  int res = -1 << 28;
  for (int i = 0; i < (n); i++) {
    string name;
    int add, mi, score = 0;
    cin >> name;
    cin >> add >> mi;
    score = 100 * add - mi * 50;
    for (int j = 0; j < (5); j++) {
      int v;
      cin >> v;
      score += v;
    }
    if (score > res) {
      res = score;
      ans = name;
    }
  }
  cout << ans << endl;
}
