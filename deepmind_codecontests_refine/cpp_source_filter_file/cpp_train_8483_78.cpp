#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int a, b, diff = 0, same = 0;
  cin >> a >> b;
  if (a > b) {
    diff = b;
    same = a;
  } else {
    diff = a;
    same = b;
  }
  same -= diff;
  same /= 2;
  cout << diff << same;
}
