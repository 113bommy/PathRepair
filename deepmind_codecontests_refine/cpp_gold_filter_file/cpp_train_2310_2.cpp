#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
void K_K() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  K_K();
  string s;
  cin >> s;
  char c = s[0];
  cout << "Mike"
       << "\n";
  for (int i = 1; i < (int)(s.size()); i++) {
    if (s[i] <= c)
      cout << "Mike"
           << "\n";
    else
      cout << "Ann"
           << "\n";
    c = min(c, s[i]);
  }
}
