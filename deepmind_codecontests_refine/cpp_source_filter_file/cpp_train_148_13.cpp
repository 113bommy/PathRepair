#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int s = 0;
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    s += x;
  }
  if (s % 5)
    cout << "-1";
  else
    cout << s / 5;
}
