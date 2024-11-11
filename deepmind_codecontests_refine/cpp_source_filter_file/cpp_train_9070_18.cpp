#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w1, w2, h1, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  long long int tot = w1 + 2 + 2 * h1;
  if (w2 == w1) {
    tot += w2 + 2 * h2 + 2;
  } else {
    tot += w2 + 2 * h2 + 2 + 1;
  }
  cout << tot << endl;
}
