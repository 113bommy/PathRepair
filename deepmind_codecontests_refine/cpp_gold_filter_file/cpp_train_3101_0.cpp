#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, C;
  cin >> A >> B >> C;
  cout << ((C > 2 * sqrtl(A * B) + A + B) ? "Yes" : "No") << "\n";
}