#include <bits/stdc++.h>
using namespace std;

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  cout << min({P + Q, Q + R, R + P}) << "\n";
}