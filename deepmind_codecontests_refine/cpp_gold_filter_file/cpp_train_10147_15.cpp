#include <bits/stdc++.h>
using namespace std;
void MySolution();
void Editorial();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) {
    MySolution();
  }
  return 0;
}
void MySolution() {
  int n;
  cin >> n;
  if (n % 2 != 0)
    cout << "black\n";
  else {
    cout << "white\n";
    cout << "1 2\n";
  }
}
void Editorial() { MySolution(); }
