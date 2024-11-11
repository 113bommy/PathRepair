#include <bits/stdc++.h>
using namespace std;
int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  cout << min(P + Q, max(Q + R, R + P));
}
