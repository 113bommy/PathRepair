#include <bits/stdc++.h>
using namespace std;
int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  cout << max({P + Q, Q + R, R + P}) << endl;
}
