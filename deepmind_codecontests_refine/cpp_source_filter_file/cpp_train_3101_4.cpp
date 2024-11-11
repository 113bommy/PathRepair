#include <bits/stdc++.h>
using namespace std;
int main() {
  long A, B, C;
  cin >> A >> B >> C;
  cout << ((C > 2 * sqrt(A * B) + A + B) ? "Yes" : "No") << "\n";
}
