#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0;
  string w;
  cin >> n;
  cin >> w;
  for (int i = 0; i < (signed)w.length(); i++) {
    if (w.at(i) == 'A') a++;
  }
  if (a > n / 2)
    cout << "Anton";
  else if (a < (double)n / 2)
    cout << "Danik";
  else
    cout << "Friendship";
  return 0;
}
