#include <bits/stdc++.h>
using namespace std;
int main() {
  int w1, w2, h1, h2, m;
  cin >> w1;
  cin >> h1;
  cin >> w2;
  cin >> h2;
  int j = (w1 + w2 + h1 + h2 + h1 + h2 + 4);
  if (w1 == w2)
    cout << j << endl;
  else
    m = (w1 - w2);
  cout << j + m << endl;
}
