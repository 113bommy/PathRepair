#include <bits/stdc++.h>
using namespace std;
string s;
void update(int l, int r, char c1, char c2) {
  for (int i = l - 1; i < r; i++)
    if (s[i] == c1) s[i] = c2;
}
int main() {
  int n, q;
  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < q; i++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    update(l, r, c1, c2);
  }
  cout << s;
  return 0;
}
